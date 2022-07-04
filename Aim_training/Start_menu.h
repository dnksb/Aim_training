#pragma once

#include <Windows.h>
#include "action_training.h"
#include "recoil_pattern_training.h"
#include "static_training.h"
#include <iostream>
#include <fstream>
#include "tinyxml2.h"

namespace Aimtraining {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Start_menu
	/// </summary>
	public ref class Start_menu : public System::Windows::Forms::Form
	{
	public:
		Start_menu(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Start_menu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ static_circle;
	private: System::Windows::Forms::Button^ action_circle;
	private: System::Windows::Forms::Button^ recoil_pattern;
	private: System::Windows::Forms::Button^ export_excel;
	protected:

	protected:



	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Start_menu::typeid));
			this->static_circle = (gcnew System::Windows::Forms::Button());
			this->action_circle = (gcnew System::Windows::Forms::Button());
			this->recoil_pattern = (gcnew System::Windows::Forms::Button());
			this->export_excel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// static_circle
			// 
			this->static_circle->BackColor = System::Drawing::Color::DimGray;
			this->static_circle->Location = System::Drawing::Point(575, 56);
			this->static_circle->Name = L"static_circle";
			this->static_circle->Size = System::Drawing::Size(216, 23);
			this->static_circle->TabIndex = 0;
			this->static_circle->Text = L"тренировка статичными кружками";
			this->static_circle->UseVisualStyleBackColor = false;
			this->static_circle->Click += gcnew System::EventHandler(this, &Start_menu::static_circle_Click);
			// 
			// action_circle
			// 
			this->action_circle->BackColor = System::Drawing::Color::DimGray;
			this->action_circle->Location = System::Drawing::Point(575, 85);
			this->action_circle->Name = L"action_circle";
			this->action_circle->Size = System::Drawing::Size(216, 23);
			this->action_circle->TabIndex = 2;
			this->action_circle->Text = L"тренировка движущимис€ кругами";
			this->action_circle->UseVisualStyleBackColor = false;
			this->action_circle->Click += gcnew System::EventHandler(this, &Start_menu::button2_Click);
			// 
			// recoil_pattern
			// 
			this->recoil_pattern->BackColor = System::Drawing::Color::DimGray;
			this->recoil_pattern->Location = System::Drawing::Point(575, 114);
			this->recoil_pattern->Name = L"recoil_pattern";
			this->recoil_pattern->Size = System::Drawing::Size(216, 23);
			this->recoil_pattern->TabIndex = 4;
			this->recoil_pattern->Text = L"тренировка рисунка отдачи";
			this->recoil_pattern->UseVisualStyleBackColor = false;
			this->recoil_pattern->Click += gcnew System::EventHandler(this, &Start_menu::button3_Click);
			// 
			// export_excel
			// 
			this->export_excel->BackColor = System::Drawing::Color::DimGray;
			this->export_excel->Location = System::Drawing::Point(575, 143);
			this->export_excel->Name = L"export_excel";
			this->export_excel->Size = System::Drawing::Size(216, 23);
			this->export_excel->TabIndex = 5;
			this->export_excel->Text = L"экспортировать в Excel";
			this->export_excel->UseVisualStyleBackColor = false;
			this->export_excel->Click += gcnew System::EventHandler(this, &Start_menu::export_excel_Click);
			// 
			// Start_menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(875, 277);
			this->Controls->Add(this->export_excel);
			this->Controls->Add(this->recoil_pattern);
			this->Controls->Add(this->action_circle);
			this->Controls->Add(this->static_circle);
			this->Name = L"Start_menu";
			this->Text = L"Start_menu";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		action_training window;
		window.ShowDialog();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		recoil_pattern_training window;
		window.ShowDialog();
	}
	private: System::Void static_circle_Click(System::Object^ sender, System::EventArgs^ e) {
		static_training window;
		window.ShowDialog();
	}
	private: System::Void export_excel_Click(System::Object^ sender, System::EventArgs^ e) {
		std::ofstream export_file("export_data.csv");
		if (!export_file.is_open()) {
			MessageBox::Show("неудалось создать/открыть файл дл€ экспорта");
			return;
		}
		tinyxml2::XMLDocument* data_base = new tinyxml2::XMLDocument("data.xml");
		if (data_base->LoadFile("data.xml") == tinyxml2::XML_SUCCESS) {
			tinyxml2::XMLElement* data = data_base->FirstChildElement("VERTICAL");
			tinyxml2::XMLElement* data_time = data_base->FirstChildElement("VERTICAL_TIME");
			export_file << "верикально" << "\nпопаданий: " << data->DoubleAttribute("value") << "\nср. врем€: " << data_time->DoubleAttribute("value") << "мс\n";
			data = data_base->FirstChildElement("HORIZONTAL");
			data_time = data_base->FirstChildElement("HORIZONTAL_TIME");
			export_file << "горизонтально" << "\nпопаданий: " << data->DoubleAttribute("value") << "\nср. врем€: " << data_time->DoubleAttribute("value") << "мс\n";
			data = data_base->FirstChildElement("DIOGANAL1");
			data_time = data_base->FirstChildElement("DIOGANAL1_TIME");
			export_file << "по диоганали \\" << "\nпопаданий: " << data->DoubleAttribute("value") << "\nср. врем€: " << data_time->DoubleAttribute("value") << "мс\n";
			data = data_base->FirstChildElement("DIOGANAL2");
			data_time = data_base->FirstChildElement("DIOGANAL2_TIME");
			export_file << "по диоганали /" << "\nпопаданий: " << data->DoubleAttribute("value") << "\nср. врем€: " << data_time->DoubleAttribute("value") << "мс\n";
			data = data_base->FirstChildElement("CIRCLE");
			data_time = data_base->FirstChildElement("CIRCLE_TIME");
			export_file << "по кругу" << "\nпопаданий: " << data->DoubleAttribute("value") << "\nср. врем€: " << data_time->DoubleAttribute("value") << "мс\n";
			data = data_base->FirstChildElement("RANDOM");
			data_time = data_base->FirstChildElement("RANDOM_TIME");
			export_file << "случайное положение" << "\nпопаданий: " << data->DoubleAttribute("value") << "\nср. врем€: " << data_time->DoubleAttribute("value") << "мс\n";
			data = data_base->FirstChildElement("AK47");
			export_file << "ak-47" << "\nточность: " << data->DoubleAttribute("value");
			data = data_base->FirstChildElement("M4A4");
			export_file << "\nm4a4" << "\nточность: " << data->DoubleAttribute("value");
			data = data_base->FirstChildElement("M4A1S");
			export_file << "\nm4a1-s" << "\nточность: " << data->DoubleAttribute("value");
			data = data_base->FirstChildElement("AUG");
			export_file << "\naug" << "\nточность: " << data->DoubleAttribute("value");
			data = data_base->FirstChildElement("GALIL");
			export_file << "\ngalil" << "\nточность: " << data->DoubleAttribute("value");
			data = data_base->FirstChildElement("FAMAS");
			export_file << "\nfamas" << "\nточность: " << data->DoubleAttribute("value");
		}
		export_file.close();
		MessageBox::Show("экспортирование прошло успешно");
	}
};
}
