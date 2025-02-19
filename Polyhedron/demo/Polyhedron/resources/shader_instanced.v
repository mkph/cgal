#version 330
attribute highp vec4 vertex;
attribute highp vec3 normals;
attribute highp vec3 colors;
attribute highp vec3 center;
uniform highp mat4 mvp_matrix;
uniform highp mat4 mv_matrix;
varying highp vec4 fP;
varying highp vec3 fN;
varying highp vec4 color;


void main(void)
{
color = vec4(colors, 1.0);
fP = mv_matrix * vertex;
fN = mat3(mv_matrix)* normals;
   gl_Position =  mvp_matrix * vec4(vertex.x + center.x, vertex.y + center.y, vertex.z + center.z, 1.0) ;
}
