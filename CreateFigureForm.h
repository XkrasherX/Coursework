#pragma once
#include "FigureException.h"
#include "EnterCoordinatesWindow.h"

namespace CursovaChemerysDanyloPZ23 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CreateFigureForm
	/// </summary>
	public ref class CreateFigureForm : public System::Windows::Forms::Form
	{
	public:
		CreateFigureForm(void)
		{
			InitializeComponent();
			result_figure = nullptr;
		}

		Figure GetResultFigure() { return *result_figure; }

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CreateFigureForm()
		{
			if (components)
			{
				delete components;
			}
			if (result_figure) {
				delete result_figure;
				result_figure = nullptr;
			}
		}
	private: System::Windows::Forms::Label^ FigureNameLabel;
	private: System::Windows::Forms::TextBox^ CreateFigureNameTextBox;
	private: System::Windows::Forms::Label^ NumOfSegmentsLabel;
	private: System::Windows::Forms::TextBox^ CreateNumOfSegmentsTextBox;
	private: System::Windows::Forms::Button^ SaveDataSegmentsButtom;
	private: System::Windows::Forms::Button^ CancelSaveDataSegmentsButton;
	protected:

	protected:

	private:
		Figure* result_figure;
		System::String^ figureName;
		int segmentsCount;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CreateFigureForm::typeid));
			this->FigureNameLabel = (gcnew System::Windows::Forms::Label());
			this->CreateFigureNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->NumOfSegmentsLabel = (gcnew System::Windows::Forms::Label());
			this->CreateNumOfSegmentsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SaveDataSegmentsButtom = (gcnew System::Windows::Forms::Button());
			this->CancelSaveDataSegmentsButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// FigureNameLabel
			// 
			this->FigureNameLabel->AutoSize = true;
			this->FigureNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FigureNameLabel->Location = System::Drawing::Point(42, 60);
			this->FigureNameLabel->Name = L"FigureNameLabel";
			this->FigureNameLabel->Size = System::Drawing::Size(259, 29);
			this->FigureNameLabel->TabIndex = 0;
			this->FigureNameLabel->Text = L"Введіть назву фігури:";
			this->FigureNameLabel->Click += gcnew System::EventHandler(this, &CreateFigureForm::label1_Click);
			// 
			// CreateFigureNameTextBox
			// 
			this->CreateFigureNameTextBox->BackColor = System::Drawing::Color::LightPink;
			this->CreateFigureNameTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CreateFigureNameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->CreateFigureNameTextBox->Location = System::Drawing::Point(307, 60);
			this->CreateFigureNameTextBox->Name = L"CreateFigureNameTextBox";
			this->CreateFigureNameTextBox->Size = System::Drawing::Size(271, 35);
			this->CreateFigureNameTextBox->TabIndex = 1;
			// 
			// NumOfSegmentsLabel
			// 
			this->NumOfSegmentsLabel->AutoSize = true;
			this->NumOfSegmentsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NumOfSegmentsLabel->Location = System::Drawing::Point(42, 169);
			this->NumOfSegmentsLabel->Name = L"NumOfSegmentsLabel";
			this->NumOfSegmentsLabel->Size = System::Drawing::Size(323, 29);
			this->NumOfSegmentsLabel->TabIndex = 2;
			this->NumOfSegmentsLabel->Text = L"Введіть кількість відрізків: ";
			// 
			// CreateNumOfSegmentsTextBox
			// 
			this->CreateNumOfSegmentsTextBox->BackColor = System::Drawing::Color::LightPink;
			this->CreateNumOfSegmentsTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CreateNumOfSegmentsTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->CreateNumOfSegmentsTextBox->Location = System::Drawing::Point(371, 169);
			this->CreateNumOfSegmentsTextBox->Name = L"CreateNumOfSegmentsTextBox";
			this->CreateNumOfSegmentsTextBox->Size = System::Drawing::Size(207, 35);
			this->CreateNumOfSegmentsTextBox->TabIndex = 3;
			// 
			// SaveDataSegmentsButtom
			// 
			this->SaveDataSegmentsButtom->BackColor = System::Drawing::Color::LightPink;
			this->SaveDataSegmentsButtom->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SaveDataSegmentsButtom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->SaveDataSegmentsButtom->Location = System::Drawing::Point(89, 273);
			this->SaveDataSegmentsButtom->Name = L"SaveDataSegmentsButtom";
			this->SaveDataSegmentsButtom->Size = System::Drawing::Size(173, 46);
			this->SaveDataSegmentsButtom->TabIndex = 4;
			this->SaveDataSegmentsButtom->Text = L"Зберегти";
			this->SaveDataSegmentsButtom->UseVisualStyleBackColor = false;
			this->SaveDataSegmentsButtom->Click += gcnew System::EventHandler(this, &CreateFigureForm::SaveDataSegmentsButtom_Click);
			// 
			// CancelSaveDataSegmentsButton
			// 
			this->CancelSaveDataSegmentsButton->BackColor = System::Drawing::Color::LightPink;
			this->CancelSaveDataSegmentsButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->CancelSaveDataSegmentsButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CancelSaveDataSegmentsButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->CancelSaveDataSegmentsButton->Location = System::Drawing::Point(382, 273);
			this->CancelSaveDataSegmentsButton->Name = L"CancelSaveDataSegmentsButton";
			this->CancelSaveDataSegmentsButton->Size = System::Drawing::Size(168, 46);
			this->CancelSaveDataSegmentsButton->TabIndex = 5;
			this->CancelSaveDataSegmentsButton->Text = L"Скасувати";
			this->CancelSaveDataSegmentsButton->UseVisualStyleBackColor = false;
			// 
			// CreateFigureForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::Pink;
			this->ClientSize = System::Drawing::Size(657, 341);
			this->Controls->Add(this->CancelSaveDataSegmentsButton);
			this->Controls->Add(this->SaveDataSegmentsButtom);
			this->Controls->Add(this->CreateNumOfSegmentsTextBox);
			this->Controls->Add(this->NumOfSegmentsLabel);
			this->Controls->Add(this->CreateFigureNameTextBox);
			this->Controls->Add(this->FigureNameLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"CreateFigureForm";
			this->Text = L"Створення фігури";
			this->Load += gcnew System::EventHandler(this, &CreateFigureForm::CreateFigureForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void CreateFigureForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void SaveDataSegmentsButtom_Click(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			System::String^ enteredName = CreateFigureNameTextBox->Text->Trim();

			if (enteredName->Length == 0)
			{
				throw FigureException(L"Введіть назву фігури.");
			}

			int count;
			bool isNumber = Int32::TryParse(CreateNumOfSegmentsTextBox->Text, count);

			if (!isNumber)
			{
				throw FigureException(L"Кількість відрізків має бути цілим числом.");
			}

			if (count < 3)
			{
				throw FigureException(L"Фігура повинна складатися щонайменше з 3 відрізків.");
			}

			EnterCoordinatesWindow^ coordsForm = gcnew EnterCoordinatesWindow(enteredName, count);
			System::Windows::Forms::DialogResult coordsResult = coordsForm->ShowDialog();

			if (coordsResult == System::Windows::Forms::DialogResult::OK)
			{
				delete result_figure;
				result_figure = new Figure(coordsForm->GetResultFigure());

				this->DialogResult = System::Windows::Forms::DialogResult::OK;
				this->Close();
			}
			// якщо Cancel - нічого не робимо, CreateFigureForm лишається відкритою
		}
		catch (FigureException& ex)
		{
			System::String^ msg = gcnew System::String(ex.GetMessage().c_str());
			MessageBox::Show(msg, L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
};
}
