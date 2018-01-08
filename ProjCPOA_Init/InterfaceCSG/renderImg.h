#ifndef RENDERIMG_H
#define RENDERIMG_H

#include <QGLWidget>
#include <QTimer>

#include "Image2Grey.h"
//#include "vec2f.h"
#include "Particule.h"
#include "Vec2.h"
#include "VecVf.h"
#include "Image.h"
#include "BoundingBox.h"
#include "Fontaine.h"

//forward declaration
class BoundingBox;

class RenderImg : public QGLWidget
{
	Q_OBJECT

	QTimer *m_timer;

public:
    RenderImg(BoundingBox& bb, QWidget *parent = 0);
	~RenderImg();

	void loadTexture(const std::string& filename);
	void updateDataTexture();

    Image2Grey& getImg();
	unsigned int getWidth();
	unsigned int getHeight();

	/**
	 * @brief clean image
	 */
	void clean();


   /**
	* @brief update sobel image
	*/
   void toggleSobel();

   /**
	* @brief setif BB has to be drawn
	* @param v
	*/
   void setBBDraw(bool v) { m_BBdraw = v;}

   /// Point Source
   float pointSize;
   Vec2<float> pointSource;

protected slots:
	void animate();

protected:
	/// Qt callbacks
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void keyPressEvent(QKeyEvent* event);
	void keyReleaseEvent(QKeyEvent* event);

    /// Tableau de Vecteur
    int nbrVec;
    VecVf* tabVec;




	/// transform win coordinate in texel image coordinate
	void coordInTexture(QMouseEvent *event, int& x, int& y);

	/// transform img coord to GL [-1,+1]
	inline float xImg2GL(float x)
	{
		return -1.0f + (2.0f*x)/float(m_widthTex-1);
	}

	/// transform img coord to GL [-1,+1]
	inline float yImg2GL(float y)
    {
		return 1.0f - (2.0f*y)/float(m_heightTex-1);// minus because of GL is bottom to up and image up to boytom
	}

    Image2Grey m_img;

	/// Texture information
	GLuint m_texture;
	int m_widthTex;
	int m_heightTex;
	unsigned char* m_ptrTex;

	/// GL Widget sizes
	int m_winW;
	int m_winH;
	int m_winS;

	/// for mouse move
	QPoint m_lastPos;
	/// key modifier state (shift/ctrl/...)
	int m_state_modifier;

	bool m_drawSobel;

	bool m_BBdraw;
    BoundingBox& m_BB;


	void drawBB(const BoundingBox& bb);

	void drawSobel();

    std::vector<Particule*> vec_particule;

//	ici les declaration de:
//   - l'image a niveau de gris
//	 - l'image gradiant'

//	 la fontaine de particule
    Fontaine fontain;
};

#endif // RENDERIMG_H
