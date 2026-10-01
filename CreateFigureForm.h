#pragma once

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
			//
			//TODO: Add the constructor code here
			//
		}

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
			this->CreateNumOfSegmentsTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->CreateNumOfSegmentsTextBox->Location = System::Drawing::Point(371, 169);
			this->CreateNumOfSegmentsTextBox->Name = L"CreateNumOfSegmentsTextBox";
			this->CreateNumOfSegmentsTextBox->Size = System::Drawing::Size(207, 35);
			this->CreateNumOfSegmentsTextBox->TabIndex = 3;
			// 
			// SaveDataSegmentsButtom
			// 
			this->SaveDataSegmentsButtom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->SaveDataSegmentsButtom->Location = System::Drawing::Point(96, 273);
			this->SaveDataSegmentsButtom->Name = L"SaveDataSegmentsButtom";
			this->SaveDataSegmentsButtom->Size = System::Drawing::Size(145, 46);
			this->SaveDataSegmentsButtom->TabIndex = 4;
			this->SaveDataSegmentsButtom->Text = L"Зберегти";
			this->SaveDataSegmentsButtom->UseVisualStyleBackColor = true;
			// 
			// CancelSaveDataSegmentsButton
			// 
			this->CancelSaveDataSegmentsButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->CancelSaveDataSegmentsButton->Location = System::Drawing::Point(391, 273);
			this->CancelSaveDataSegmentsButton->Name = L"CancelSaveDataSegmentsButton";
			this->CancelSaveDataSegmentsButton->Size = System::Drawing::Size(145, 46);
			this->CancelSaveDataSegmentsButton->TabIndex = 4;
			this->CancelSaveDataSegmentsButton->Text = L"Скасувати";
			this->CancelSaveDataSegmentsButton->UseVisualStyleBackColor = true;
			// 
			// CreateFigureForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(706, 341);
			this->Controls->Add(this->CancelSaveDataSegmentsButton);
			this->Controls->Add(this->SaveDataSegmentsButtom);
			this->Controls->Add(this->CreateNumOfSegmentsTextBox);
			this->Controls->Add(this->NumOfSegmentsLabel);
			this->Controls->Add(this->CreateFigureNameTextBox);
			this->Controls->Add(this->FigureNameLabel);
			this->Name = L"CreateFigureForm";
			this->Text = L"CreateFigureForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
