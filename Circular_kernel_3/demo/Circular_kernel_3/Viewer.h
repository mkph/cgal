#include <QGLViewer/qglviewer.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

typedef CGAL::Exact_predicates_inexact_constructions_kernel EPIC;

class Viewer : public QGLViewer, QOpenGLFunctions_3_3_Core
{
public:
    Viewer(QWidget* parent = 0);
  GLuint dl_nb;
protected :
  virtual void draw();
  virtual void init();
  template<class Output_iterator>
  void naive_compute_intersection_points(const std::vector<EPIC::Point_3>&,Output_iterator) const;
private:
  //Shaders elements

  int vertexLocation[3];
  int normalsLocation[3];
  int centerLocation;
  int trivialCenterLocation;
  int mvpLocation;
  int mvLocation;
  int colorLocation;
  int lightLocation[5];


  std::vector<float> pos_points;
  std::vector<float> pos_lines;
  std::vector<float> pos_sphere;
  std::vector<float> pos_sphere_inter;
  std::vector<float> normals;
  std::vector<float> normals_inter;
  std::vector<float> trivial_center;
  std::vector<float> normals_lines;

  QOpenGLBuffer buffers[9];
  QOpenGLVertexArrayObject vao[3];
  QOpenGLShaderProgram rendering_program;

  void initialize_buffers();
  void compute_elements();
  void attrib_buffers(QGLViewer*);
  void compile_shaders();

};
