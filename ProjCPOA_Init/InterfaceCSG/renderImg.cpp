#include "renderImg.h"
#include <QMouseEvent>
#include <iostream>

//#include "imgGradient.h"
//#include "boundingbox.h"
#include <limits>
#include "Array.h"
#include "Vec2.h"
#include "GradientSobel.h"



RenderImg::RenderImg(BoundingBox& bb, QWidget *parent ):
	QGLWidget(QGLFormat(QGL::SampleBuffers), parent),
	m_texture(0),
	m_widthTex(0),
	m_heightTex(0),
	m_ptrTex(NULL),
    m_img(1024,1024),
	m_drawSobel(false),
    m_BBdraw(false),
    //m_img(16,16)
    m_BB(bb)
  // QQ INIT A AJOUTER ?

{
    m_heightTex = m_img.height();
    m_widthTex = m_img.width();
    m_timer = new QTimer(this);
    m_timer->setInterval(20);
    m_ptrTex = m_img.data_pix();
    vec_particule.push_back(new Particule(Vec2f({-1,-1}),Vec2f({-1,-1})));
    connect(m_timer, SIGNAL(timeout()), this, SLOT(animate()));
    // Init Vecteur, et point Source
        pointSize = 3.;
        nbrVec = 100;
        tabVec = new VecVf[nbrVec]();
	// VOTRE CODE ICI

}


void RenderImg::loadTexture(const std::string& filename)
{
	// VOTRE CODE ICI

	glBindTexture(GL_TEXTURE_2D, m_texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, m_widthTex, m_heightTex, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, m_ptrTex);
	glBindTexture(GL_TEXTURE_2D, 0);
}



void RenderImg::updateDataTexture()
{

    m_ptrTex = m_img.data_pix();
	glBindTexture(GL_TEXTURE_2D, m_texture);
	glTexSubImage2D(GL_TEXTURE_2D,0,0,0,m_widthTex, m_heightTex, GL_LUMINANCE, GL_UNSIGNED_BYTE, m_ptrTex);
    glBindTexture(GL_TEXTURE_2D, 0);
	updateGL();
}

Image2Grey& RenderImg::getImg(){
    return m_img;
}


unsigned int RenderImg::getWidth()
{
    return m_img.width(); // RETURN IMAGE WIDTH
}

unsigned int RenderImg::getHeight()
{
        return m_img.height(); // RETURN IMAGE HEIGHT
}

RenderImg::~RenderImg()
{
	glDeleteTextures(1, &m_texture);
	m_texture = 0;
}

void RenderImg::initializeGL()
{
	glClearColor(0.0f,0.0f,0.4f,0.0f);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);

	glGenTextures(1, &m_texture);
	glBindTexture(GL_TEXTURE_2D, m_texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, m_widthTex, m_heightTex, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, m_ptrTex);
	glBindTexture(GL_TEXTURE_2D, 0);


}

void RenderImg::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_texture);

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex2f( -1,1);
	glTexCoord2f(0,1);
	glVertex2f(-1,-1);
	glTexCoord2f(1,1);
	glVertex2f( 1,-1);
	glTexCoord2f(1,0);
	glVertex2f( 1,1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);

	// for debugging
	if (m_drawSobel)
		drawSobel();

    if (m_BBdraw)
        drawBB(m_BB);

    glPointSize(pointSize);
    glColor3f(1,0,0);
    glBegin(GL_POINTS);
    /*for (int i = 0; i < nbrVec; i++ )
    {
        glVertex2fv(tabVec[i].get_ptr());
    }*/
    unsigned int nbp = vec_particule.size();// VOTRE CODE ICI : nombre de particules
    for (unsigned int i = 0; i < nbp; i++ )
    {
        //std::cout << vec_particule[i]->pos << " vitesse " << vec_particule[i]->vitesse << " horloge " << vec_particule[i]->horloge << std::endl;
        // here get back position of each particle in ptPos
        glVertex2f(2.0f*vec_particule[i]->pos[0]/m_widthTex-1.0f, -2.0f*vec_particule[i]->pos[1]/m_heightTex+1.0f);
    }
    glEnd();

}

void RenderImg::resizeGL(int width, int height)
{
	m_winW = width;
	m_winH = height;
	int side = qMin(width, height);
	m_winS = side;
	glViewport((width - side) / 2, (height - side) / 2, side, side);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	update();
}

void RenderImg::coordInTexture(QMouseEvent *event, int& x, int& y)
{
	if (m_winS == m_winW)
	{
		x = (float(event->x())/m_winW)*m_widthTex;
		y = (float(event->y()-(m_winH-m_winS)/2)/m_winH)*m_heightTex;
	}
	else
	{
		x = (float(event->x()-(m_winW-m_winS)/2)/m_winH)*m_widthTex;
		y = (float(event->y())/m_winH)*m_heightTex;
	}
}


void RenderImg::mousePressEvent(QMouseEvent *event)
{
	int x,y;
	coordInTexture(event, x, y);
	m_lastPos.setX(x);
	m_lastPos.setY(y);

	std::cout << "Mouse-press in widget"<< event->x() << " / "<< event->y() << std::endl;
	std::cout << " =>  position in texture "<< x << " / "<< y << std::endl;

	if (m_state_modifier & Qt::ShiftModifier)
		std::cout << "     with Shift" << std::endl;
	if (m_state_modifier & Qt::ControlModifier)
		std::cout << "     with Ctrl" << std::endl;

    Particule* p = new Particule(Vec2f({(float)x,(float)y}),Vec2f({0.f,0.f}));

    vec_particule.push_back(p);
    fontain.append(p);


	paintGL();

    glPointSize(4.0f);
	glColor3f(1.0f,0,0);
	glBegin(GL_POINTS);

    unsigned int nbp = vec_particule.size();// VOTRE CODE ICI : nombre de particules
    for (unsigned int i = 0; i < nbp; i++ )
    {
		// here get back position of each particle in ptPos
        glVertex2f(2.0f*vec_particule[i]->pos[0]/m_widthTex-1.0f, -2.0f*vec_particule[i]->pos[1]/m_heightTex+1.0f);
	}
	glEnd();

    swapBuffers();
}


void RenderImg::mouseReleaseEvent(QMouseEvent *event)
{
//	int x,y;
//	coordInTexture(event, x, y);
//	m_lastPos.setX(x);
//	m_lastPos.setY(y);

//	std::cout << " RELEASE in texture "<< x << " / "<< y << std::endl;

}

void RenderImg::keyPressEvent(QKeyEvent* event)
{
	m_state_modifier = event->modifiers();
    unsigned int nbp = vec_particule.size();
    Image2D<Vec2f> grad = GradientSobel::Sobel(m_img);

	switch(event->key())
	{
		case 'A':
            std::cout << " touche a enfoncee" << std::endl;
			break;
		case 'E':
			// qq init



            for (unsigned int i = 0; i < nbp; i++ )
            {
                // here get back position of each particle in ptPos
                vec_particule[i]->initIm(m_img,grad);
            }
            m_timer->start();

            //fontain.move_all();
            //update();
			break;
		case 'S':
			m_timer->stop();
			// ??
			break;
		case 'P':
			if (m_timer->isActive())
				m_timer->stop();
			else
				m_timer->start();
			break;
	}
    std::cout << "keyPress" << std::endl;
	update();

}


void RenderImg::animate()
{
    /*for(int i=0; i<nbrVec ; i++){
            tabVec[i].avance(pointSource[0],pointSource[1]);
    }*/
    fontain.move_all();
    update();
}



void RenderImg::keyReleaseEvent(QKeyEvent* /*event*/)
{
	m_state_modifier = 0;
}


void RenderImg::clean()
{
	unsigned char* ptr=m_ptrTex;

	for (int i=0; i<m_heightTex; ++i)
	{
		for (int j=0; j<m_widthTex; ++j)
        {
			*ptr++ = 0;
		}
	}
}

void RenderImg::toggleSobel()
{
	m_drawSobel = !m_drawSobel;
	if (m_drawSobel)
	{
//		m_img = m_img.average(2);
//		m_grad = GradientSobel::gradient33(m_img);
//		m_img.threshold(128);
		updateDataTexture();
	}
	update();
}


void RenderImg::drawSobel()
{
	glBegin(GL_LINES);
	for (int j=0; j<m_heightTex; j+=2)
	{
		for (int i=0; i<m_widthTex; i+=2)
		{
			// get value of gradiant
			// Vec2f v = ??

//			if (v*v > 0.001f)
//			{
//				float x = -1.0f + (2.0f*i)/(m_widthTex-1);
//				float y = 1.0f  - (2.0f*j)/(m_heightTex-1);// minus because of GL is bottom to up and image up to boytom
//				v *= 4.0f/m_widthTex;
//				glColor3f(1.0f,1.0f,0.0f);
//				glVertex2f(x,y);
//				glColor3f(1.0f,0.0f,0.0f);
//				glVertex2f(x+v[0],y-v[1]);
//			}
		}
	}
	glEnd();
}


void RenderImg::drawBB(const BoundingBox& bb)
{
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f,0.5f,0.f);
    /*for(int i=0;i<250;++i){
        for(int j=0;j<250;++j){
            glVertex2f( xImg2GL(i), yImg2GL(j) );
        }
    }
    glVertex2f( xImg2GL(0), yImg2GL(0) );
    glVertex2f( xImg2GL(250), yImg2GL(0) );
    glVertex2f( xImg2GL(250), yImg2GL(250) );
    glVertex2f( xImg2GL(0), yImg2GL(250) );*/

    glVertex2f( xImg2GL(bb.p1[0]), yImg2GL(bb.p1[1]) );
    glVertex2f( xImg2GL(bb.p1[0]), yImg2GL(bb.p2[1]) );
    glVertex2f( xImg2GL(bb.p2[0]), yImg2GL(bb.p2[1]) );
    glVertex2f( xImg2GL(bb.p2[0]), yImg2GL(bb.p1[1]) );
	glEnd();
}

