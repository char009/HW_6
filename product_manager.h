#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include "sales_associate.h"
#include "locomotor.h"

//void My_Callback4(Fl_Widget*w, void* userdata);
void My_Callback11(Fl_Widget*w, void* userdata)
{
	// LOCOMOTOR
	win->hide();
	loc();

}
void My_Callback12(Fl_Widget*w, void* userdata)
{
	//ARM
}
void My_Callback13(Fl_Widget*w, void* userdata)
{
	// BATTERY
}
void My_Callback14(Fl_Widget*w, void* userdata)
{
	// TORSO
}
void My_Callback15(Fl_Widget*w, void* userdata)
{
	// HEAD
	
}

void My_Callback4(Fl_Widget*w, void* userdata)
{
	//Make Robot Components"
	win->hide();

	win = new Fl_Window{ 600, 400, "Make Robot Components" };
		Fl_Button button1(50, 50, 200, 30, "LOCOMOTOR");
		Fl_Button button2(50, 100, 200, 30, "ARM");
		Fl_Button button3(50, 150, 200, 30, "BATTERY");
		Fl_Button button4(50, 200, 200, 30, "TORSO");
		Fl_Button button5(50, 250, 200, 30, "HEAD");


		button1.callback(My_Callback11);
		button2.callback(My_Callback12);
		button3.callback(My_Callback13);
		button4.callback(My_Callback14);
		button5.callback(My_Callback15);

	win->show(); // hide this
	Fl::run();
}
void My_Callback5(Fl_Widget*w, void* userdata)
{
	// Make Robot Models
}
void My_Callback6(Fl_Widget*w, void* userdata)
{
	// Print Component Catalog
}

void My_Callback7(Fl_Widget*w, void* userdata)
{
	// "Print Robot Catalog
}


void create_robot_partCBPM(Fl_Widget* w, void* p) { // Replace with call to model!
	win->hide();

	
		//return ;
	cout << rp_user->value() <<"   "<<rp_pass->value();

	//if (!(strcmp(rp_user->value(), "PMRRS") == 0 && strcmp(rp_pass->value(), "char009") == 0))
	//	return;

	win = new Fl_Window{ 600, 400, "PM Shop Manager" };

	Fl_Button button1(50, 50, 200, 30, "Make Robot Components");
	Fl_Button button2(50, 100, 200, 30, "Make Robot Models");
	Fl_Button button3(50, 150, 200, 30, "Print Component Catalog");
	Fl_Button button4(50, 200, 200, 30, "Print Robot Catalog");

	button1.callback(My_Callback4);
	button2.callback(My_Callback5);
	button3.callback(My_Callback6);
	button4.callback(My_Callback7);

	win->show(); // hide this
	Fl::run();
}

void pm()
{	
	//Fl_Window win2(300, 300, "Login PM");
	win = new Fl_Window{ 600, 400, "PM Login Shop Manager" };
	rp_user = new Fl_Input(90, 40, 210, 25, "User Name");
	rp_user->align(FL_ALIGN_LEFT);
	rp_pass = new Fl_Input(90, 70, 210, 25, "Password");
	rp_pass->align(FL_ALIGN_LEFT);

	Fl_Return_Button *rp_login;
	rp_login = new Fl_Return_Button(100, 100, 120, 25, "Login");
	 
	rp_login->callback((Fl_Callback *)create_robot_partCBPM, 0);
	
	
	
	//button4.callback(My_Callback);
	win->show();
	Fl::run();
}