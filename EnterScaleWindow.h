#pragma once

namespace CursovaChemerysDanyloPZ23 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EnterScaleWindow
	/// </summary>
	public ref class EnterScaleWindow : public System::Windows::Forms::Form
	{
	public:
		EnterScaleWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		property double Factor
		{
			double get() { return Convert::ToDouble(NumericUpDown->Value); }
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EnterScaleWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ FactorLabel;
	protected:
	private: System::Windows::Forms::NumericUpDown^ NumericUpDown;
	private: System::Windows::Forms::Button^ ApplyButton;
	private: System::Windows::Forms::Button^ CancelButton2;

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
			this->FactorLabel = (gcnew System::Windows::Forms::Label());
			this->NumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->ApplyButton = (gcnew System::Windows::Forms::Button());
			this->CancelButton2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumericUpDown))->BeginInit();
			this->SuspendLayout();
			// 
			// FactorLabel
			// 
			this->FactorLabel->AutoSize = true;
			this->FactorLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FactorLabel->Location = System::Drawing::Point(12, 23);
			this->FactorLabel->Name = L"FactorLabel";
			this->FactorLabel->Size = System::Drawing::Size(336, 29);
			this->FactorLabel->TabIndex = 0;
			this->FactorLabel->Text = L"Коефіцієнт масштабування:";
			// 
			// NumericUpDown
			// 
			this->NumericUpDown->DecimalPlaces = 2;
			this->NumericUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NumericUpDown->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->NumericUpDown->Location = System::Drawing::Point(354, 23);
			this->NumericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->NumericUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->NumericUpDown->Name = L"NumericUpDown";
			this->NumericUpDown->Size = System::Drawing::Size(82, 35);
			this->NumericUpDown->TabIndex = 1;
			this->NumericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// ApplyButton
			// 
			this->ApplyButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ApplyButton->Location = System::Drawing::Point(42, 97);
			this->ApplyButton->Name = L"ApplyButton";
			this->ApplyButton->Size = System::Drawing::Size(139, 51);
			this->ApplyButton->TabIndex = 2;
			this->ApplyButton->Text = L"Зберегти";
			this->ApplyButton->UseVisualStyleBackColor = true;
			// 
			// CancelButton2
			// 
			this->CancelButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CancelButton2->Location = System::Drawing::Point(250, 97);
			this->CancelButton2->Name = L"CancelButton2";
			this->CancelButton2->Size = System::Drawing::Size(139, 51);
			this->CancelButton2->TabIndex = 2;
			this->CancelButton2->Text = L"Скасувати";
			this->CancelButton2->UseVisualStyleBackColor = true;
			// 
			// EnterScaleWindow
			// 
			this->AcceptButton = this->ApplyButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->CancelButton2;
			this->ClientSize = System::Drawing::Size(452, 174);
			this->Controls->Add(this->CancelButton2);
			this->Controls->Add(this->ApplyButton);
			this->Controls->Add(this->NumericUpDown);
			this->Controls->Add(this->FactorLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"EnterScaleWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EnterScaleWindow";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumericUpDown))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
