//Вікно для вводу коефіцієнта масштабування фігури
#pragma once
#include "FigureException.h"

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

		double getFactor()
		{
			return factor;
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
		double factor;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(EnterScaleWindow::typeid));
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
			this->NumericUpDown->BackColor = System::Drawing::Color::LightPink;
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
			this->ApplyButton->BackColor = System::Drawing::Color::LightPink;
			this->ApplyButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ApplyButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ApplyButton->Location = System::Drawing::Point(42, 97);
			this->ApplyButton->Name = L"ApplyButton";
			this->ApplyButton->Size = System::Drawing::Size(139, 51);
			this->ApplyButton->TabIndex = 2;
			this->ApplyButton->Text = L"Зберегти";
			this->ApplyButton->UseVisualStyleBackColor = false;
			this->ApplyButton->Click += gcnew System::EventHandler(this, &EnterScaleWindow::ApplyButton_Click);
			// 
			// CancelButton2
			// 
			this->CancelButton2->BackColor = System::Drawing::Color::LightPink;
			this->CancelButton2->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->CancelButton2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CancelButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CancelButton2->Location = System::Drawing::Point(250, 97);
			this->CancelButton2->Name = L"CancelButton2";
			this->CancelButton2->Size = System::Drawing::Size(146, 51);
			this->CancelButton2->TabIndex = 2;
			this->CancelButton2->Text = L"Скасувати";
			this->CancelButton2->UseVisualStyleBackColor = false;
			this->CancelButton2->Click += gcnew System::EventHandler(this, &EnterScaleWindow::CancelButton2_Click);
			// 
			// EnterScaleWindow
			// 
			this->AcceptButton = this->ApplyButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Pink;
			this->CancelButton = this->CancelButton2;
			this->ClientSize = System::Drawing::Size(452, 174);
			this->Controls->Add(this->CancelButton2);
			this->Controls->Add(this->ApplyButton);
			this->Controls->Add(this->NumericUpDown);
			this->Controls->Add(this->FactorLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"EnterScaleWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Введіть коефіцієнт масштабування";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumericUpDown))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//кнопка для зберігання коефіцієнта
	private: System::Void ApplyButton_Click(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			double value;
			bool ok = Double::TryParse(NumericUpDown->Text, value);

			if (!ok)
			{
				throw FigureException(L"Коефіцієнт масштабування має бути числом.");
			}

			if (value <= 0)
			{
				throw FigureException(L"Коефіцієнт масштабування має бути додатним числом.");
			}

			factor = value;

			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
		catch (FigureException& ex)
		{
			System::String^ msg = gcnew System::String(ex.GetMessage().c_str());
			MessageBox::Show(msg, L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	
	//кнопка для скасування дії
	private: System::Void CancelButton2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->Close();
	}
};
}
