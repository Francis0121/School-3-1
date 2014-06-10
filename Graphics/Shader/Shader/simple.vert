uniform mat4 u_mvp_matrix; // 4���� Matrix
attribute vec4 a_vertex; 
attribute vec2 a_texcoord;

varying vec2 v_texcoord;
// �Ӽ� Vector 
//attribute vec3 a_color;
//varying vec3 v_color;
 
void main()
{
	// 4 ���� Matrix * Vector �ε� 
	// 4 �� * 3 �� ������ homogenous�� ���� ������ 1.0 �� ������ ���ҷ� �߰����Ѽ� Vector�� ���Ѵ�.
	v_texcoord = a_texcoord;
	gl_Position = u_mvp_matrix * a_vertex;
	//v_color = a_color;
}