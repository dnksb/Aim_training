#pragma once

#include <iostream>
#include <math.h>
#include "tinyxml2.h"

struct circle {
	int X;
	int Y;
	bool show = true;
};

namespace Aimtraining {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� static_training
	/// </summary>
	public ref class static_training : public System::Windows::Forms::Form
	{
	public:
	public:
		Graphics^ ground; //��������� ������ - �������, �� ������� ����� ��������
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::NumericUpDown^ interval;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	public:

		   Pen^ pen; //��������� ������ - ��������, ������� ����� �������� ������
		   Random rand;
	private: System::Windows::Forms::Button^ restart_count;
	private: System::Windows::Forms::Label^ output_count;
	private: System::Windows::Forms::Label^ time;
		   SolidBrush^ Brush = gcnew SolidBrush(Color::BlueViolet);
	public:
		static_training(void) {
			InitializeComponent();
			pen = gcnew Pen(Color::WhiteSmoke);
			ground = pictureBox1->CreateGraphics();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~static_training()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::NumericUpDown^ amount_circle;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ start_button;
	private: System::Windows::Forms::Button^ stop_button;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NumericUpDown^ radius;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;


	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(static_training::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->amount_circle = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->start_button = (gcnew System::Windows::Forms::Button());
			this->stop_button = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->radius = (gcnew System::Windows::Forms::NumericUpDown());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->interval = (gcnew System::Windows::Forms::NumericUpDown());
			this->restart_count = (gcnew System::Windows::Forms::Button());
			this->output_count = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->time = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->amount_circle))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->radius))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->interval))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Cross;
			this->pictureBox1->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.ErrorImage")));
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(750, 750);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->WaitOnLoad = true;
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &static_training::pictureBox1_MouseDown);
			// 
			// amount_circle
			// 
			this->amount_circle->BackColor = System::Drawing::Color::DimGray;
			this->amount_circle->Location = System::Drawing::Point(778, 55);
			this->amount_circle->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->amount_circle->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->amount_circle->Name = L"amount_circle";
			this->amount_circle->Size = System::Drawing::Size(156, 20);
			this->amount_circle->TabIndex = 1;
			this->amount_circle->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->amount_circle->ValueChanged += gcnew System::EventHandler(this, &static_training::amount_circle_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::DimGray;
			this->label1->Location = System::Drawing::Point(775, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(111, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"���������� �������";
			// 
			// start_button
			// 
			this->start_button->BackColor = System::Drawing::Color::DimGray;
			this->start_button->Location = System::Drawing::Point(859, 13);
			this->start_button->Name = L"start_button";
			this->start_button->Size = System::Drawing::Size(75, 23);
			this->start_button->TabIndex = 3;
			this->start_button->Text = L"�����";
			this->start_button->UseVisualStyleBackColor = false;
			this->start_button->Click += gcnew System::EventHandler(this, &static_training::start_button_Click);
			// 
			// stop_button
			// 
			this->stop_button->BackColor = System::Drawing::Color::DimGray;
			this->stop_button->Location = System::Drawing::Point(778, 13);
			this->stop_button->Name = L"stop_button";
			this->stop_button->Size = System::Drawing::Size(75, 23);
			this->stop_button->TabIndex = 4;
			this->stop_button->Text = L"����";
			this->stop_button->UseVisualStyleBackColor = false;
			this->stop_button->Click += gcnew System::EventHandler(this, &static_training::stop_button_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::DimGray;
			this->label2->Location = System::Drawing::Point(775, 78);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(88, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"������ �������";
			// 
			// radius
			// 
			this->radius->BackColor = System::Drawing::Color::DimGray;
			this->radius->Location = System::Drawing::Point(778, 94);
			this->radius->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 70, 0, 0, 0 });
			this->radius->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->radius->Name = L"radius";
			this->radius->Size = System::Drawing::Size(156, 20);
			this->radius->TabIndex = 5;
			this->radius->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->radius->ValueChanged += gcnew System::EventHandler(this, &static_training::radius_ValueChanged);
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &static_training::timer1_Tick);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::DimGray;
			this->label3->Location = System::Drawing::Point(775, 117);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(161, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"�������� ����� �����������";
			// 
			// interval
			// 
			this->interval->BackColor = System::Drawing::Color::DimGray;
			this->interval->Location = System::Drawing::Point(778, 133);
			this->interval->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5000, 0, 0, 0 });
			this->interval->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->interval->Name = L"interval";
			this->interval->Size = System::Drawing::Size(156, 20);
			this->interval->TabIndex = 7;
			this->interval->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->interval->ValueChanged += gcnew System::EventHandler(this, &static_training::interval_ValueChanged);
			// 
			// restart_count
			// 
			this->restart_count->BackColor = System::Drawing::Color::DimGray;
			this->restart_count->Location = System::Drawing::Point(778, 192);
			this->restart_count->Name = L"restart_count";
			this->restart_count->Size = System::Drawing::Size(104, 23);
			this->restart_count->TabIndex = 19;
			this->restart_count->Text = L"�������� ����";
			this->restart_count->UseVisualStyleBackColor = false;
			this->restart_count->Click += gcnew System::EventHandler(this, &static_training::restart_count_Click);
			// 
			// output_count
			// 
			this->output_count->AutoSize = true;
			this->output_count->BackColor = System::Drawing::Color::DimGray;
			this->output_count->Location = System::Drawing::Point(775, 160);
			this->output_count->Name = L"output_count";
			this->output_count->Size = System::Drawing::Size(41, 13);
			this->output_count->TabIndex = 18;
			this->output_count->Text = L"����: 0";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->BackColor = System::Drawing::Color::DimGray;
			this->checkBox1->Location = System::Drawing::Point(779, 221);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(74, 17);
			this->checkBox1->TabIndex = 23;
			this->checkBox1->Text = L"��������";
			this->checkBox1->UseVisualStyleBackColor = false;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &static_training::checkBox1_CheckedChanged);
			// 
			// time
			// 
			this->time->AutoSize = true;
			this->time->BackColor = System::Drawing::Color::DimGray;
			this->time->Location = System::Drawing::Point(775, 176);
			this->time->Name = L"time";
			this->time->Size = System::Drawing::Size(113, 13);
			this->time->TabIndex = 20;
			this->time->Text = L"������� �����: 0 ��";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::DimGray;
			this->label5->Location = System::Drawing::Point(776, 241);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(103, 13);
			this->label5->TabIndex = 24;
			this->label5->Text = L"���������� ������";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->BackColor = System::Drawing::Color::DimGray;
			this->numericUpDown1->Location = System::Drawing::Point(779, 258);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 300, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 20);
			this->numericUpDown1->TabIndex = 25;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &static_training::timer_ValueChanged);
			// 
			// static_training
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(946, 783);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->time);
			this->Controls->Add(this->restart_count);
			this->Controls->Add(this->output_count);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->interval);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->radius);
			this->Controls->Add(this->stop_button);
			this->Controls->Add(this->start_button);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->amount_circle);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"static_training";
			this->Text = L"static_training";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->amount_circle))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->radius))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->interval))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		//���������� �������
		int amount_circles = 1;
		//������ �������
		int circle_radius = 10;
		//������ �������
		circle* circle_array = new circle[amount_circles];
		//���� ���������� (false-���)
		bool start_training = false;
		//������� �������
		int tick_interval = 1000;
		//���������� ��������� �� �������
		int count = 0;
		//����� ������� �������, ����� ����������� �������, ����� ������ ����������(��� ���������� �� �����)
		clock_t start, end, start_time;
		//��� �� ����� ������ ������ (true-���)
		bool first_circle = true;
		//������ ������� ����� ���������
		int* click_time = new int(1);
		//���������� �� ����� (false-���)
		bool time_traning = false;
		//�������� ����� ���������� �� �����
		int time_stop = 1000;
		//�������� ����� ��� ������ �����������
		tinyxml2::XMLDocument* data_base = new tinyxml2::XMLDocument("data.xml");
	private:
		//��������� ������
		void DrawCircle(int x, int y) {
			ground->FillEllipse(Brush, x, y, circle_radius, circle_radius);
			ground->DrawEllipse(pen, x, y, circle_radius, circle_radius);
		}
		//���������� ������ � ������
		int* add_circle(int* arr, int razm) {
			int* newmas = new int[razm + 1];
			for (int i = 0; i < razm; i++) {
				newmas[i] = arr[i];
			}
			delete[] arr;
			return newmas;
		}
		//�������� ������ �� �������
		int* delete_circle(int* arr, int razm) {
			int* newmas = new int[razm - 1];
			for (int i = 0; i < razm - 1; i++) {
				newmas[i] = arr[i];
			}
			delete[] arr;
			return newmas;
		}
		//���������� ������ � ������
		circle* add_circle(circle* arr, int razm) {
			circle* newmas = new circle[razm + 1];
			for (int i = 0; i < razm; i++) {
				newmas[i] = arr[i];
			}
			delete[] arr;
			return newmas;
		}
		//�������� ������ �� �������
		circle* delete_circle(circle* arr, int razm) {
			circle* newmas = new circle[razm - 1];
			for (int i = 0; i < razm - 1; i++) {
				newmas[i] = arr[i];
			}
			delete[] arr;
			return newmas;
		}
		//������� �������� �������
		int count_time(int* arr, int razm) {
			int sum = 0;
			for (int i = 1; i < razm; i++) {
				sum += arr[i];
			}
			try {
				return sum / (razm - 1);
			}
			catch (System::DivideByZeroException^ ex) {
				return sum;
			}
		}
	private:
		//������ ����������
		System::Void start_button_Click(System::Object^ sender, System::EventArgs^ e) {
			timer1->Enabled = true;
			start_training = true;
			first_circle = true;
			start_time = clock();
			for (int i = 0; i < amount_circles; i++) {
				circle_array[i].X = rand.Next(pictureBox1->Width - circle_radius);
				circle_array[i].Y = rand.Next(pictureBox1->Height - circle_radius);
				DrawCircle(circle_array[i].X, circle_array[i].Y);
			}
		}
	private: 
		//��������� �����������
		System::Void stop_button_Click(System::Object^ sender, System::EventArgs^ e) {
			timer1->Enabled = false;
			start_training = false;
		}
	private:
		//��������� �������� ������� (������������ ����������)
		System::Void timer_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
			timer1->Enabled = false;
			start_training = false;
			time_stop = Convert::ToInt32(numericUpDown1->Value) * 1000;
			while (count > 0) {
				click_time = delete_circle(click_time, count);
				count--;
			}
			click_time = new int(1);
			time->Text = "������� �����: 0 ��";
			output_count->Text = "����: 0";
		}
	private:
		//��������� ���������� �������
		System::Void amount_circle_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
			timer1->Enabled = false;
			start_training = false;
			if (amount_circle->Value > amount_circles) {
				circle_array = add_circle(circle_array, amount_circles);
			}
			else {
				circle_array = delete_circle(circle_array, amount_circles);
			}
			amount_circles = Convert::ToInt32(amount_circle->Value);
			while (count > 0) {
				click_time = delete_circle(click_time, count);
				count--;
			}
			click_time = new int(1);
			time->Text = "������� �����: 0 ��";
			output_count->Text = "����: 0";
		}
	private: 
		//��������� ������� ������
		System::Void radius_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
			timer1->Enabled = false;
			start_training = false;
			circle_radius = Convert::ToInt32(radius->Value);
			while (count > 0) {
				click_time = delete_circle(click_time, count);
				count--;
			}
			click_time = new int(1);
			time->Text = "������� �����: 0 ��";
			output_count->Text = "����: 0";
		}
	private:
		//��������� �������� ����� ��������� �������
		System::Void interval_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
			timer1->Enabled = false;
			start_training = false;
			timer1->Interval = Convert::ToInt32(interval->Value);
			tick_interval = Convert::ToInt32(interval->Value);
			while (count > 0) {
				click_time = delete_circle(click_time, count);
				count--;
			}
			click_time = new int(1);
			time->Text = "������� �����: 0 ��";
			output_count->Text = "����: 0";
		}
	private:
		//������� � ��������� ������� �� ������
		System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
			if (time_traning) {
				if (clock() - start_time > time_stop) {
					timer1->Enabled = false;
					start_training = false;
					MessageBox::Show("���� ������� �����: " + Convert::ToString(count_time(click_time, count)));
					if (data_base->LoadFile("data.xml") == tinyxml2::XML_SUCCESS) {
						tinyxml2::XMLElement* RECORD = data_base->FirstChildElement("RANDOM");
						RECORD->SetAttribute("value", count);
						tinyxml2::XMLElement* TIME = data_base->FirstChildElement("RANDOM_TIME");
						TIME->SetAttribute("value", count_time(click_time, count));
						data_base->SaveFile("data.xml");
					}
				}
			}
		}
	private:
		//��������� ������� �� ������ ����
		System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			if (!start_training) {
				return;
			}
			for (int i = 0; i < amount_circles; i++) {
				int c_y = abs(this->Location.Y - Cursor->Position.Y) - 43;
				int c_x = abs(this->Location.X - Cursor->Position.X) - 20;
				int x = c_x - (circle_array[i].X + circle_radius / 2);
				int y = c_y - (circle_array[i].Y + circle_radius / 2);
				if (sqrt(pow(x, 2) + pow(y, 2)) <= circle_radius / 2) {
					if (first_circle) {
						start = clock();
						first_circle = false;
						count++;
						output_count->Text = "����: " + Convert::ToString(count);
						click_time[0] = 0;
						end = clock();
					}
					else {
						click_time = add_circle(click_time, count);
						output_count->Text = "����: " + Convert::ToString(count);
						click_time[count] = clock() - end;
						end = clock();
						count++;
						time->Text = "������� �����: " + Convert::ToString(count_time(click_time, count)) + " ��";
					}
					circle_array[i].X = rand.Next(pictureBox1->Width - circle_radius);
					circle_array[i].Y = rand.Next(pictureBox1->Height - circle_radius);
				}
			}
			ground->DrawImage(pictureBox1->Image, Point(0, 0));
			for (int i = 0; i < amount_circles; i++) {
				if (circle_array[i].show) {
					DrawCircle(circle_array[i].X, circle_array[i].Y);
				}
			}
		}
	private:
		//���������� ����������
		System::Void restart_count_Click(System::Object^ sender, System::EventArgs^ e) {
			timer1->Enabled = false;
			start_training = false;
			while (count > 0) {
				click_time = delete_circle(click_time, count);
				count--;
			}
			click_time = new int(1);
			time->Text = "������� �����: 0 ��";
			output_count->Text = "����: 0";
		}
	private:
		//����� ���������� �� �����
		System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			time_traning = !time_traning;
		}
};
}
