#version 120

varying vec4 ex_position;
varying vec4 ex_color;

uniform vec2 lightPos;

void main()
{
	float extensity = 1.0f / length(ex_position.xy - lightPos);
	gl_FragColor = ex_color * extensity;
}