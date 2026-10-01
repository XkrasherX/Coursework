#pragma once

#include "FigureManage.h"

namespace CursovaChemerysDanyloPZ23 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			manage = new FigureManage;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			delete manage;
			if (components)
			{
				delete components;
			}
		}
	private: FigureManage* manage;
	private: System::Windows::Forms::Panel^ DrawingField;
	protected:

	private: System::Windows::Forms::Button^ CreateFigureButton;
	private: System::Windows::Forms::Button^ ClearFieldButton;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ CalculatePerimeterButton;
	private: System::Windows::Forms::Button^ CalculcateCircleAreaButton;
	private: System::Windows::Forms::Button^ LargestAreaButton;
	private: System::Windows::Forms::Button^ SortFiguresButton;
	private: System::Windows::Forms::Button^ ScaleFigureButton;






	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->DrawingField = (gcnew System::Windows::Forms::Panel());
			this->CreateFigureButton = (gcnew System::Windows::Forms::Button());
			this->ClearFieldButton = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->CalculatePerimeterButton = (gcnew System::Windows::Forms::Button());
			this->CalculcateCircleAreaButton = (gcnew System::Windows::Forms::Button());
			this->LargestAreaButton = (gcnew System::Windows::Forms::Button());
			this->SortFiguresButton = (gcnew System::Windows::Forms::Button());
			this->ScaleFigureButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// DrawingField
			// 
			this->DrawingField->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->DrawingField->Location = System::Drawing::Point(1, 2);
			this->DrawingField->Name = L"DrawingField";
			this->DrawingField->Size = System::Drawing::Size(715, 715);
			this->DrawingField->TabIndex = 0;
			this->DrawingField->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainWindow::DrawingField_Paint);
			// 
			// CreateFigureButton
			// 
			this->CreateFigureButton->Location = System::Drawing::Point(755, 35);
			this->CreateFigureButton->Name = L"CreateFigureButton";
			this->CreateFigureButton->Size = System::Drawing::Size(258, 57);
			this->CreateFigureButton->TabIndex = 1;
			this->CreateFigureButton->Text = L"Створити фігуру";
			this->CreateFigureButton->UseVisualStyleBackColor = true;
			// 
			// ClearFieldButton
			// 
			this->ClearFieldButton->Location = System::Drawing::Point(755, 125);
			this->ClearFieldButton->Name = L"ClearFieldButton";
			this->ClearFieldButton->Size = System::Drawing::Size(258, 57);
			this->ClearFieldButton->TabIndex = 1;
			this->ClearFieldButton->Text = L"Очистити поле";
			this->ClearFieldButton->UseVisualStyleBackColor = true;
			this->ClearFieldButton->Click += gcnew System::EventHandler(this, &MainWindow::ClearFieldButton_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Bisque;
			this->textBox1->Location = System::Drawing::Point(755, 200);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(258, 197);
			this->textBox1->TabIndex = 2;
			// 
			// CalculatePerimeterButton
			// 
			this->CalculatePerimeterButton->Location = System::Drawing::Point(755, 414);
			this->CalculatePerimeterButton->Name = L"CalculatePerimeterButton";
			this->CalculatePerimeterButton->Size = System::Drawing::Size(119, 57);
			this->CalculatePerimeterButton->TabIndex = 1;
			this->CalculatePerimeterButton->Text = L"Периметр";
			this->CalculatePerimeterButton->UseVisualStyleBackColor = true;
			// 
			// CalculcateCircleAreaButton
			// 
			this->CalculcateCircleAreaButton->Location = System::Drawing::Point(895, 414);
			this->CalculcateCircleAreaButton->Name = L"CalculcateCircleAreaButton";
			this->CalculcateCircleAreaButton->Size = System::Drawing::Size(118, 57);
			this->CalculcateCircleAreaButton->TabIndex = 1;
			this->CalculcateCircleAreaButton->Text = L"Площа впис. кола";
			this->CalculcateCircleAreaButton->UseVisualStyleBackColor = true;
			// 
			// LargestAreaButton
			// 
			this->LargestAreaButton->Location = System::Drawing::Point(755, 487);
			this->LargestAreaButton->Name = L"LargestAreaButton";
			this->LargestAreaButton->Size = System::Drawing::Size(258, 57);
			this->LargestAreaButton->TabIndex = 1;
			this->LargestAreaButton->Text = L"Найбільша площа";
			this->LargestAreaButton->UseVisualStyleBackColor = true;
			// 
			// SortFiguresButton
			// 
			this->SortFiguresButton->Location = System::Drawing::Point(755, 561);
			this->SortFiguresButton->Name = L"SortFiguresButton";
			this->SortFiguresButton->Size = System::Drawing::Size(258, 57);
			this->SortFiguresButton->TabIndex = 1;
			this->SortFiguresButton->Text = L"Сортування";
			this->SortFiguresButton->UseVisualStyleBackColor = true;
			// 
			// ScaleFigureButton
			// 
			this->ScaleFigureButton->Location = System::Drawing::Point(755, 636);
			this->ScaleFigureButton->Name = L"ScaleFigureButton";
			this->ScaleFigureButton->Size = System::Drawing::Size(258, 57);
			this->ScaleFigureButton->TabIndex = 1;
			this->ScaleFigureButton->Text = L"Масштабування фігури";
			this->ScaleFigureButton->UseVisualStyleBackColor = true;
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1045, 717);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->CalculcateCircleAreaButton);
			this->Controls->Add(this->CalculatePerimeterButton);
			this->Controls->Add(this->ScaleFigureButton);
			this->Controls->Add(this->SortFiguresButton);
			this->Controls->Add(this->LargestAreaButton);
			this->Controls->Add(this->ClearFieldButton);
			this->Controls->Add(this->CreateFigureButton);
			this->Controls->Add(this->DrawingField);
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//Поле, де будуть відображатися фігури
	private: System::Void DrawingField_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Pen^ pen = gcnew Pen(Color::Black, 2);
		int count = manage->getCount();

		for (int i = 0;i < count; i++) {
			Figure figure = manage->getFigure(i);
			int segment_count = figure.GetSegmentsCount();

			for (int j = 0; j < segment_count; j++) {
				Segment segment = figure.GetSegment(j);
				PointSegment p1 = segment.getStart();
				PointSegment p2 = segment.getEnd();

				e->Graphics->DrawLine(pen, p1.x, p1.y, p2.x, p2.y);
			}

		}
	}
private: System::Void ClearFieldButton_Click(System::Object^ sender, System::EventArgs^ e) {
	manage->clearAll();
	DrawingField->Invalidate();
}
};
}
