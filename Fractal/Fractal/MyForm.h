#pragma once
#include <iostream>
#include <windows.h>

struct TFPoint
{
	float x;
	float y;
};
TFPoint *a;
int z = 0;
int summator = 0;
float k = 0.5;

namespace Fractal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;




	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(746, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(91, 32);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Draw";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(637, 11);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(87, 35);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Resize";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(849, 572);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::MyForm_Scroll);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->ResumeLayout(false);

		}

		void serp2(float x1, float y1, float x2, float y2, float x3, float y3, int n, Graphics^ g)
		{
			if (n > 0)
			{
				SolidBrush ^ trnsRedBrush = gcnew SolidBrush(Color::FromArgb(100, 100, 100, 100));
				Pen^ pen = gcnew Pen(trnsRedBrush); // или (Color::Red)
				float new_x1, new_x2, new_x3, new_y1, new_y2, new_y3;
				new_x1 = (x1 + x2) / 2;
				new_y1 = (y1 + y2) / 2;
				new_x2 = (x2 + x3) / 2;
				new_y2 = (y2 + y3) / 2;
				new_x3 = (x1 + x3) / 2;
				new_y3 = (y1 + y3) / 2;

				a[z].x = new_x1;
				a[z].y = new_y1;
				z = z + 1;
				a[z].x = new_x2;
				a[z].y = new_y2;
				z = z + 1;
				a[z].x = new_x3;
				a[z].y = new_y3;
				g->DrawLine(pen, new_x1, new_y1, new_x2, new_y2);
				g->DrawLine(pen, new_x2, new_y2, new_x3, new_y3);
				g->DrawLine(pen, new_x3, new_y3, new_x1, new_y1);
				z = z + 1;
				serp2(x1, y1, new_x1, new_y1, new_x3, new_y3, n - 1, g);
				serp2(x2, y2, new_x1, new_y1, new_x2, new_y2, n - 1, g);
				serp2(x3, y3, new_x2, new_y2, new_x3, new_y3, n - 1, g);
			}
		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		///remove start
		SolidBrush ^ trnsRedBrush = gcnew SolidBrush(Color::FromArgb(100, 100, 100, 100));
		Pen^ pen = gcnew Pen(trnsRedBrush); // или (Color::Red)
		///remove end

		int final = 7;
		int n = 3;
		int z = 0;
		int s = 0;
		int v = 0;
		int f = 0;
		while (s < final)
		{
			n = 3 * n - 3;
			s = s + 1;
		}
		f = round(n);
		a = new TFPoint[f];
		Graphics^ im = MyForm::CreateGraphics();
		serp2(500, 500,   600, 350,   700, 500, final, im);
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		Graphics^ im = MyForm::CreateGraphics();
		SolidBrush ^ trnsRedBrush = gcnew SolidBrush(Color::FromArgb(100, 100, 100, 100));
		Pen^ pen = gcnew Pen(trnsRedBrush); // или (Color::Red)


		summator++;
		int final = 7;
		int n = 3;
		int z = 0;
		int s = 0;
		int v = 0;
		int f = 0;
		while (s < final)
		{
			n = 3 * n - 3;
			s = s + 1;
		}
		f = round(n);
		float x = a[11].x;
		int q = 500;
		int w = 500;
		int i = 0;
		if (summator > 4)
		{
			summator = summator - 4;
			k = -0.5;
		}
		else 
		{
			im->Clear(Color::White);
		}

		while (i < f)
		{
			a[i].x = (a[i].x + k * (a[i].x - q));
			a[i].y = (a[i].y + k * (a[i].y - w));
			//
			a[i + 1].x = (a[i + 1].x + k * (a[i + 1].x - q));
			a[i + 1].y = (a[i + 1].y + k * (a[i + 1].y - w));
			//
			a[i + 2].x = (a[i + 2].x + k * (a[i + 2].x - q));
			a[i + 2].y = (a[i + 2].y + k * (a[i + 2].y - w));
			//
			im->DrawLine(pen, a[i].x, a[i].y, a[i + 1].x, a[i + 1].y);
			im->DrawLine(pen, a[i + 1].x, a[i + 1].y, a[i + 2].x, a[i + 2].y);
			im->DrawLine(pen, a[i + 2].x, a[i + 2].y, a[i].x, a[i].y);
			i = i + 3;
		}
	}
private: System::Void MyForm_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {

}
private: System::Void MyForm_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

}
};
}
