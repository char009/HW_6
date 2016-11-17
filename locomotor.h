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
#include "product_manager.h"

Fl_Input *choice;

void choose_locomotor(Fl_Widget* w, void* p) { // Replace with call to model!
	win->hide();

	cout << "Locomotor Choice " << choice->value();

	win->show(); // DELETE THIS

				 // choose that locomotor according to value of locomotor choice
}

void loc()
{
	win = new Fl_Window{ 600, 400, "Locomotor" };
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 640 - 40, 250 - 40, "File Output");
	disp->buffer(buff);
	win->resizable(*disp);
	//win->show();
	string line, display_line = "";
	ifstream myfile("locomotor.txt");
	int i = 1;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			line = std::to_string(i) + ". " + line;
			line += "\n";
			cout << line;
			display_line += line;
			//cout << i<<". "<< display_line;
			i++;
		}
		myfile.close();
	}

	else cout << "Unable to open file";

	const char *line1 = display_line.c_str();
	buff->text(line1);

	cout << "No. of lines" << i - 1;

	choice = new Fl_Input(200, 260, 210, 25, "Choose a Locomotor Number"); // change coordinates of placement

	Fl_Return_Button *rp_confirm;
	rp_confirm = new Fl_Return_Button(150, 300, 120, 25, "Confirm");
	rp_confirm->callback((Fl_Callback *)choose_locomotor, 0);

	Fl_Return_Button *returnback;
	returnback = new Fl_Return_Button(150, 350, 220, 25, "Return for new component");
	//returnback->callback((Fl_Callback *)My_Callback4, 0);

	//returnback->callback(My_Callback4);

	win->show(); // hide this
	Fl::run();
}