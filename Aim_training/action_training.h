#pragma once

#include <iostream>
#include <math.h>
#include "tinyxml2.h"

namespace Aimtraining {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для action_training
	/// </summary>
	public ref class action_training : public System::Windows::Forms::Form {
	public:
	public:
		Graphics^ ground; //объявляем объект - графику, на которой будем рисовать
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::NumericUpDown^ interval;
	public:

		Pen^ pen; //объявляем объект - карандаш, которым будем рисовать контур
		Random rand;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::RadioButton^ vertical;
	private: System::Windows::Forms::RadioButton^ horizontal;
	private: System::Windows::Forms::RadioButton^ circle;
	private: System::Windows::Forms::RadioButton^ dioganal_1;
	private: System::Windows::Forms::RadioButton^ dioganal_2;
	private: System::Windows::Forms::Label^ output_count;
	private: System::Windows::Forms::Button^ restart_count;
	private: System::Windows::Forms::Label^ time;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;




	private: SolidBrush^ Brush = gcnew SolidBrush(Color::BlueViolet);
	public:
		action_training(void) {
			InitializeComponent();
			pen = gcnew Pen(Color::WhiteSmoke);
			ground = pictureBox1->CreateGraphics();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~action_training() {
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:


	private: System::Windows::Forms::Button^ start_button;
	private: System::Windows::Forms::Button^ stop_button;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NumericUpDown^ radius;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void) {
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(action_training::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->start_button = (gcnew System::Windows::Forms::Button());
			this->stop_button = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->radius = (gcnew System::Windows::Forms::NumericUpDown());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->interval = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->vertical = (gcnew System::Windows::Forms::RadioButton());
			this->horizontal = (gcnew System::Windows::Forms::RadioButton());
			this->circle = (gcnew System::Windows::Forms::RadioButton());
			this->dioganal_1 = (gcnew System::Windows::Forms::RadioButton());
			this->dioganal_2 = (gcnew System::Windows::Forms::RadioButton());
			this->output_count = (gcnew System::Windows::Forms::Label());
			this->restart_count = (gcnew System::Windows::Forms::Button());
			this->time = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->radius))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->interval))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(750, 750);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &action_training::pictureBox1_MouseDown);
			// 
			// start_button
			// 
			this->start_button->BackColor = System::Drawing::Color::DimGray;
			this->start_button->Location = System::Drawing::Point(859, 13);
			this->start_button->Name = L"start_button";
			this->start_button->Size = System::Drawing::Size(75, 23);
			this->start_button->TabIndex = 3;
			this->start_button->Text = L"старт";
			this->start_button->UseVisualStyleBackColor = false;
			this->start_button->Click += gcnew System::EventHandler(this, &action_training::start_button_Click);
			// 
			// stop_button
			// 
			this->stop_button->BackColor = System::Drawing::Color::DimGray;
			this->stop_button->Location = System::Drawing::Point(778, 13);
			this->stop_button->Name = L"stop_button";
			this->stop_button->Size = System::Drawing::Size(75, 23);
			this->stop_button->TabIndex = 4;
			this->stop_button->Text = L"стоп";
			this->stop_button->UseVisualStyleBackColor = false;
			this->stop_button->Click += gcnew System::EventHandler(this, &action_training::stop_button_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::DimGray;
			this->label2->Location = System::Drawing::Point(775, 41);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"радиус круга";
			// 
			// radius
			// 
			this->radius->BackColor = System::Drawing::Color::DimGray;
			this->radius->Location = System::Drawing::Point(778, 57);
			this->radius->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 70, 0, 0, 0 });
			this->radius->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->radius->Name = L"radius";
			this->radius->Size = System::Drawing::Size(156, 20);
			this->radius->TabIndex = 5;
			this->radius->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->radius->ValueChanged += gcnew System::EventHandler(this, &action_training::radius_ValueChanged);
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &action_training::timer1_Tick);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::DimGray;
			this->label3->Location = System::Drawing::Point(775, 80);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(85, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"скорость круга";
			// 
			// interval
			// 
			this->interval->BackColor = System::Drawing::Color::DimGray;
			this->interval->Location = System::Drawing::Point(778, 96);
			this->interval->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5000, 0, 0, 0 });
			this->interval->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->interval->Name = L"interval";
			this->interval->Size = System::Drawing::Size(156, 20);
			this->interval->TabIndex = 7;
			this->interval->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->interval->ValueChanged += gcnew System::EventHandler(this, &action_training::interval_ValueChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::DimGray;
			this->label4->Location = System::Drawing::Point(775, 119);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(129, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"тип перемещения круга";
			// 
			// vertical
			// 
			this->vertical->AutoSize = true;
			this->vertical->BackColor = System::Drawing::Color::DimGray;
			this->vertical->Checked = true;
			this->vertical->Location = System::Drawing::Point(778, 136);
			this->vertical->Name = L"vertical";
			this->vertical->Size = System::Drawing::Size(90, 17);
			this->vertical->TabIndex = 11;
			this->vertical->TabStop = true;
			this->vertical->Text = L"вертикально";
			this->vertical->UseVisualStyleBackColor = false;
			this->vertical->CheckedChanged += gcnew System::EventHandler(this, &action_training::vertical_CheckedChanged);
			// 
			// horizontal
			// 
			this->horizontal->AutoSize = true;
			this->horizontal->BackColor = System::Drawing::Color::DimGray;
			this->horizontal->Location = System::Drawing::Point(778, 160);
			this->horizontal->Name = L"horizontal";
			this->horizontal->Size = System::Drawing::Size(107, 17);
			this->horizontal->TabIndex = 12;
			this->horizontal->Text = L"горизонатально";
			this->horizontal->UseVisualStyleBackColor = false;
			this->horizontal->CheckedChanged += gcnew System::EventHandler(this, &action_training::horizontal_CheckedChanged);
			// 
			// circle
			// 
			this->circle->AutoSize = true;
			this->circle->BackColor = System::Drawing::Color::DimGray;
			this->circle->Location = System::Drawing::Point(778, 184);
			this->circle->Name = L"circle";
			this->circle->Size = System::Drawing::Size(67, 17);
			this->circle->TabIndex = 13;
			this->circle->Text = L"по кругу";
			this->circle->UseVisualStyleBackColor = false;
			this->circle->CheckedChanged += gcnew System::EventHandler(this, &action_training::circle_CheckedChanged);
			// 
			// dioganal_1
			// 
			this->dioganal_1->AutoSize = true;
			this->dioganal_1->BackColor = System::Drawing::Color::DimGray;
			this->dioganal_1->Location = System::Drawing::Point(778, 208);
			this->dioganal_1->Name = L"dioganal_1";
			this->dioganal_1->Size = System::Drawing::Size(101, 17);
			this->dioganal_1->TabIndex = 14;
			this->dioganal_1->Text = L"по диоганали /";
			this->dioganal_1->UseVisualStyleBackColor = false;
			this->dioganal_1->CheckedChanged += gcnew System::EventHandler(this, &action_training::dioganal_1_CheckedChanged);
			// 
			// dioganal_2
			// 
			this->dioganal_2->AutoSize = true;
			this->dioganal_2->BackColor = System::Drawing::Color::DimGray;
			this->dioganal_2->Location = System::Drawing::Point(778, 231);
			this->dioganal_2->Name = L"dioganal_2";
			this->dioganal_2->Size = System::Drawing::Size(101, 17);
			this->dioganal_2->TabIndex = 15;
			this->dioganal_2->Text = L"по диоганали \\";
			this->dioganal_2->UseVisualStyleBackColor = false;
			this->dioganal_2->CheckedChanged += gcnew System::EventHandler(this, &action_training::dioganal_2_CheckedChanged);
			// 
			// output_count
			// 
			this->output_count->AutoSize = true;
			this->output_count->BackColor = System::Drawing::Color::DimGray;
			this->output_count->Location = System::Drawing::Point(778, 255);
			this->output_count->Name = L"output_count";
			this->output_count->Size = System::Drawing::Size(41, 13);
			this->output_count->TabIndex = 16;
			this->output_count->Text = L"счет: 0";
			// 
			// restart_count
			// 
			this->restart_count->BackColor = System::Drawing::Color::DimGray;
			this->restart_count->Location = System::Drawing::Point(781, 284);
			this->restart_count->Name = L"restart_count";
			this->restart_count->Size = System::Drawing::Size(104, 23);
			this->restart_count->TabIndex = 17;
			this->restart_count->Text = L"сбросить счет";
			this->restart_count->UseVisualStyleBackColor = false;
			this->restart_count->Click += gcnew System::EventHandler(this, &action_training::restart_count_Click);
			// 
			// time
			// 
			this->time->AutoSize = true;
			this->time->BackColor = System::Drawing::Color::DimGray;
			this->time->Location = System::Drawing::Point(778, 268);
			this->time->Name = L"time";
			this->time->Size = System::Drawing::Size(113, 13);
			this->time->TabIndex = 21;
			this->time->Text = L"среднее время: 0 мс";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::DimGray;
			this->label1->Location = System::Drawing::Point(778, 314);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(116, 13);
			this->label1->TabIndex = 22;
			this->label1->Text = L"тренировка на время";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->BackColor = System::Drawing::Color::DimGray;
			this->checkBox1->Location = System::Drawing::Point(781, 331);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(74, 17);
			this->checkBox1->TabIndex = 23;
			this->checkBox1->Text = L"включить";
			this->checkBox1->UseVisualStyleBackColor = false;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &action_training::checkBox1_CheckedChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::DimGray;
			this->label5->Location = System::Drawing::Point(778, 351);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(103, 13);
			this->label5->TabIndex = 24;
			this->label5->Text = L"количество секунд";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->BackColor = System::Drawing::Color::DimGray;
			this->numericUpDown1->Location = System::Drawing::Point(781, 368);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 300, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 20);
			this->numericUpDown1->TabIndex = 25;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &action_training::timer_ValueChanged);
			// 
			// action_training
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(946, 783);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->time);
			this->Controls->Add(this->restart_count);
			this->Controls->Add(this->output_count);
			this->Controls->Add(this->dioganal_2);
			this->Controls->Add(this->dioganal_1);
			this->Controls->Add(this->circle);
			this->Controls->Add(this->horizontal);
			this->Controls->Add(this->vertical);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->interval);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->radius);
			this->Controls->Add(this->stop_button);
			this->Controls->Add(this->start_button);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"action_training";
			this->Text = L"action_training";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->radius))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->interval))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		//количество кружков
		int amount_circles = 1;
		//радиус кружков
		int circle_radius = 10;
		//положение кружка по Х
		int circle_x;
		//положение кружка по У
		int circle_y;
		//идет тренировка (false-нет)
		bool start_training = false;
		//скороть кружков
		int tick_interval = 1000;
		//напрвление кружков
		int direction = 10;
		//количество попаданий по кружкам
		int count = 0;
		//углы для движения по кругу
		float alpha = 0, beta = 0;
		//время первого нажатия, время последующих нажатий, время старта тренировки(для тренировки на время)
		clock_t start, end, start_time;
		//был ли нажат первый кружок (true-нет)
		bool first_circle = true;
		//массив времени между нажатиями
		int* click_time = new int(1);
		//тренировка на время (false-нет)
		bool time_traning = false;
		//конечное время тренировки на время
		int time_stop = 1000;
		//открытие файла для записи результатов
		tinyxml2::XMLDocument* data_base = new tinyxml2::XMLDocument("data.xml");
	private:
		//отрисовка гружка
		void DrawCircle(int x, int y) {
			ground->FillEllipse(Brush, x, y, circle_radius, circle_radius);
			ground->DrawEllipse(pen, x, y, circle_radius, circle_radius);
		}
		//подсчет среднего времени
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
		//добавление гружка в массив
		int* add_circle(int* arr, int razm) {
			int* newmas = new int[razm + 1];
			for (int i = 0; i < razm; i++) {
				newmas[i] = arr[i];
			}
			delete[] arr;
			return newmas;
		}
		//удаление кружка из массива
		int* delete_circle(int* arr, int razm) {
			int* newmas = new int[razm - 1];
			for (int i = 0; i < razm - 1; i++) {
				newmas[i] = arr[i];
			}
			delete[] arr;
			return newmas;
		}
	private:
		//запуск тренировки
		System::Void start_button_Click(System::Object^ sender, System::EventArgs^ e) {
			timer1->Enabled = true;
			start_training = true;
			start_time = clock();
		}
	private:
		//остановка тренировки
		System::Void stop_button_Click(System::Object^ sender, System::EventArgs^ e) {
			timer1->Enabled = false;
			start_training = false;
		}
	private:
		//изменение радиуса кружка
		System::Void radius_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
			timer1->Enabled = false;
			start_training = false;
			circle_radius = Convert::ToInt32(radius->Value);
			while (count > 0) {
				click_time = delete_circle(click_time, count);
				count--;
			}
			click_time = new int(1);
			time->Text = "среднее время: 0 мс";
			output_count->Text = "счет: 0";
		}
	private:
		//изменения значения таймера (длительность тренировки)
		System::Void timer_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
			timer1->Enabled = false;
			start_training = false;
			time_stop = Convert::ToInt32(numericUpDown1->Value) * 1000;
			while (count > 0) {
				click_time = delete_circle(click_time, count);
				count--;
			}
			click_time = new int(1);
			time->Text = "среднее время: 0 мс";
			output_count->Text = "счет: 0";
		}
	private:
		//изменение скорости кружков
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
			time->Text = "среднее время: 0 мс";
			output_count->Text = "счет: 0";
		}
	private:
		//расчеты и отрисовка кружков на холсте
		System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
			ground->DrawImage(pictureBox1->Image, Point(0, 0));
			if (vertical->Checked) {
				circle_y += direction;
				if (circle_y > pictureBox1->Height) {
					direction = -10;
				}
				else if (circle_y < 0) {
					direction = 10;
					circle_x = rand.Next(pictureBox1->Width - circle_radius);
				}
			}
			else if (horizontal->Checked) {
				circle_x += direction;
				if (circle_x > pictureBox1->Width) {
					direction = -10;
				}
				else if (circle_x < 0) {
					direction = 10;
					circle_y = rand.Next(pictureBox1->Height - circle_radius);
				}
			}
			else if (dioganal_2->Checked) {
				circle_y += direction * pictureBox1->Height * 0.01;
				circle_x += direction * pictureBox1->Width * 0.01;
				if (circle_x > pictureBox1->Width - circle_radius) {
					direction = -1;
				}
				else if (circle_x < 0) {
					direction = 1;
				}
			}
			else if (dioganal_1->Checked) {
				circle_y -= direction * 7;
				circle_x += direction * 7;
				if (circle_x > pictureBox1->Width - circle_radius) {
					direction = -1;
				}
				else if (circle_x < 0) {
					direction = 1;
				}
			}
			else if (circle->Checked) {
				circle_x = 375 + 200 * sin(alpha);
				circle_y = 375 + 200 * cos(beta);
				alpha += 0.1;
				beta += 0.1;
			}
			DrawCircle(circle_x, circle_y);
			if (time_traning) {
				if (clock() - start_time > time_stop) {
					timer1->Enabled = false;
					start_training = false;
					if (data_base->LoadFile("data.xml") == tinyxml2::XML_SUCCESS) {
						if (vertical->Checked) {
							tinyxml2::XMLElement* RECORD = data_base->FirstChildElement("VERTICAL");
							RECORD->SetAttribute("value", count);
							tinyxml2::XMLElement* TIME = data_base->FirstChildElement("VERTICAL_TIME");
							TIME->SetAttribute("value", count_time(click_time, count));
						}
						else if (horizontal->Checked) {
							tinyxml2::XMLElement* RECORD = data_base->FirstChildElement("HORIZONTAL");
							RECORD->SetAttribute("value", count);
							tinyxml2::XMLElement* TIME = data_base->FirstChildElement("HORIZONTAL_TIME");
							TIME->SetAttribute("value", count_time(click_time, count));
						}
						else if (dioganal_1->Checked) {
							tinyxml2::XMLElement* RECORD = data_base->FirstChildElement("DIOGANAL1");
							RECORD->SetAttribute("value", count);
							tinyxml2::XMLElement* TIME = data_base->FirstChildElement("DIOGANAL1_TIME");
							TIME->SetAttribute("value", count_time(click_time, count));
						}
						else if (dioganal_2->Checked) {
							tinyxml2::XMLElement* RECORD = data_base->FirstChildElement("DIOGANAL2");
							RECORD->SetAttribute("value", count);
							tinyxml2::XMLElement* TIME = data_base->FirstChildElement("DIOGANAL2_TIME");
							TIME->SetAttribute("value", count_time(click_time, count));
						}
						else if (circle->Checked) {
							tinyxml2::XMLElement* RECORD = data_base->FirstChildElement("CIRCLE");
							RECORD->SetAttribute("value", count);
							tinyxml2::XMLElement* TIME = data_base->FirstChildElement("CIRCLE_TIME");
							TIME->SetAttribute("value", count_time(click_time, count));
						}
						data_base->SaveFile("data.xml");
					}
					MessageBox::Show("ваше среднее время: " + Convert::ToString(count_time(click_time, count)));
				}
			}
		}
	private:
		//режим перемещения кружка вертикально
		System::Void vertical_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			timer1->Enabled = false;
			start_training = false;
			circle_x = pictureBox1->Width / 2;
			direction = 10;
			while (count > 0) {
				click_time = delete_circle(click_time, count);
				count--;
			}
			click_time = new int(1);
			time->Text = "среднее время: 0 мс";
			output_count->Text = "счет: 0";
		}
	private:
		//режим перемещения кружка горизонтально
		System::Void horizontal_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			timer1->Enabled = false;
			start_training = false;
			circle_y = pictureBox1->Height / 2;
			direction = 10;
			while (count > 0) {
				click_time = delete_circle(click_time, count);
				count--;
			}
			click_time = new int(1);
			time->Text = "среднее время: 0 мс";
			output_count->Text = "счет: 0";
		}
	private:
		//режим перемещения кружка по кругу
		System::Void circle_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			timer1->Enabled = false;
			start_training = false;
			circle_x = 375;
			circle_y = 375;
			while (count > 0) {
				click_time = delete_circle(click_time, count);
				count--;
			}
			click_time = new int(1);
			time->Text = "среднее время: 0 мс";
			output_count->Text = "счет: 0";
		}
	private:
		//режим перемещения кружка по диоганали вниз
		System::Void dioganal_1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			timer1->Enabled = false;
			start_training = false;
			circle_x = 1;
			circle_y = pictureBox1->Height - circle_radius;
			direction = 1;
			while (count > 0) {
				click_time = delete_circle(click_time, count);
				count--;
			}
			click_time = new int(1);
			time->Text = "среднее время: 0 мс";
			output_count->Text = "счет: 0";
		}
	private:
		//режим перемещения кружка по диоганали верх
		System::Void dioganal_2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			timer1->Enabled = false;
			start_training = false;
			circle_x = 1;
			circle_y = 1;
			direction = 1;
			while (count > 0) {
				click_time = delete_circle(click_time, count);
				count--;
			}
			click_time = new int(1);
			time->Text = "среднее время: 0 мс";
			output_count->Text = "счет: 0";
		}
	private:
		//обработка нажатия на кнопку мыши
		System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			if (!start_training) {
				return;
			}
			int c_y = abs(this->Location.Y - Cursor->Position.Y) - 43;
			int c_x = abs(this->Location.X - Cursor->Position.X) - 20;
			int x = c_x - (circle_x + circle_radius / 2);
			int y = c_y - (circle_y + circle_radius / 2);
			if (first_circle) {
				start = clock();
				first_circle = false;
				count++;
				output_count->Text = "счет: " + Convert::ToString(count);
				click_time[0] = 0;
				end = clock();
			}
			else {
				click_time = add_circle(click_time, count);
				output_count->Text = "счет: " + Convert::ToString(count);
				click_time[count] = clock() - end;
				end = clock();
				count++;
				time->Text = "среднее время: " + Convert::ToString(count_time(click_time, count)) + " мс";
			}
		}
	private:
		//перезапуск тренировки
		System::Void restart_count_Click(System::Object^ sender, System::EventArgs^ e) {
			timer1->Enabled = false;
			start_training = false;
			while (count > 0) {
				click_time = delete_circle(click_time, count);
				count--;
			}
			click_time = new int(1);
			time->Text = "среднее время: 0 мс";
			output_count->Text = "счет: 0";
		}
	private:
		//режим тренировки на время
		System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			time_traning = !time_traning;
		}
	};
}
