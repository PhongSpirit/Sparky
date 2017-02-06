#version 120

attribute vec3 in_position;
attribute vec4 in_color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

varying vec4 ex_color;
varying vec4 ex_position;

void main()
{
	gl_Position = projection * view * model * vec4(in_position, 1.0f);
	ex_position = model * vec4(in_position, 1.0f);
	ex_color = in_color;
}