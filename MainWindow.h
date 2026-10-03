//Головне вікно програми

#pragma once
#include <string>
#include <msclr/marshal_cppstd.h>

#include "FigureManage.h"
#include "CreateFigureForm.h"
#include "EnterScaleWindow.h"

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
			selected_index = -1;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			delete manage;
			manage = nullptr;
			if (components)
			{
				delete components;
			}
		}
	private: FigureManage* manage;

	private: int selected_index; 
	protected:

	private: System::Windows::Forms::Button^ CreateFigureButton;
	private: System::Windows::Forms::Button^ ClearFieldButton;


	private: System::Windows::Forms::Button^ CalculatePerimeterButton;
	private: System::Windows::Forms::Button^ CalculcateCircleAreaButton;
	private: System::Windows::Forms::Button^ LargestAreaButton;
	private: System::Windows::Forms::Button^ SortFiguresButton;
	private: System::Windows::Forms::Button^ ScaleFigureButton;
	private: System::Windows::Forms::TextBox^ InformationFigureTextBox;
	private: System::Windows::Forms::Button^ SaveToFileButton;
	private: System::Windows::Forms::Button^ LoadFromFileButton;
	private: System::Windows::Forms::ComboBox^ FigureSelectComboBox;
	private: System::Windows::Forms::Panel^ DrawingField;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			this->CreateFigureButton = (gcnew System::Windows::Forms::Button());
			this->ClearFieldButton = (gcnew System::Windows::Forms::Button());
			this->CalculatePerimeterButton = (gcnew System::Windows::Forms::Button());
			this->CalculcateCircleAreaButton = (gcnew System::Windows::Forms::Button());
			this->LargestAreaButton = (gcnew System::Windows::Forms::Button());
			this->SortFiguresButton = (gcnew System::Windows::Forms::Button());
			this->ScaleFigureButton = (gcnew System::Windows::Forms::Button());
			this->InformationFigureTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SaveToFileButton = (gcnew System::Windows::Forms::Button());
			this->LoadFromFileButton = (gcnew System::Windows::Forms::Button());
			this->FigureSelectComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->DrawingField = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// CreateFigureButton
			// 
			this->CreateFigureButton->BackColor = System::Drawing::Color::LightPink;
			this->CreateFigureButton->FlatAppearance->BorderSize = 0;
			this->CreateFigureButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CreateFigureButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CreateFigureButton->Location = System::Drawing::Point(736, 12);
			this->CreateFigureButton->Name = L"CreateFigureButton";
			this->CreateFigureButton->Size = System::Drawing::Size(297, 57);
			this->CreateFigureButton->TabIndex = 1;
			this->CreateFigureButton->Text = L"Створити фігуру";
			this->CreateFigureButton->UseVisualStyleBackColor = false;
			this->CreateFigureButton->Click += gcnew System::EventHandler(this, &MainWindow::CreateFigureButton_Click);
			// 
			// ClearFieldButton
			// 
			this->ClearFieldButton->BackColor = System::Drawing::Color::LightPink;
			this->ClearFieldButton->FlatAppearance->BorderSize = 0;
			this->ClearFieldButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ClearFieldButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ClearFieldButton->Location = System::Drawing::Point(736, 75);
			this->ClearFieldButton->Name = L"ClearFieldButton";
			this->ClearFieldButton->Size = System::Drawing::Size(297, 57);
			this->ClearFieldButton->TabIndex = 1;
			this->ClearFieldButton->Text = L"Очистити поле";
			this->ClearFieldButton->UseVisualStyleBackColor = false;
			this->ClearFieldButton->Click += gcnew System::EventHandler(this, &MainWindow::ClearFieldButton_Click);
			// 
			// CalculatePerimeterButton
			// 
			this->CalculatePerimeterButton->BackColor = System::Drawing::Color::LightPink;
			this->CalculatePerimeterButton->FlatAppearance->BorderSize = 0;
			this->CalculatePerimeterButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CalculatePerimeterButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->CalculatePerimeterButton->Location = System::Drawing::Point(736, 397);
			this->CalculatePerimeterButton->Name = L"CalculatePerimeterButton";
			this->CalculatePerimeterButton->Size = System::Drawing::Size(138, 57);
			this->CalculatePerimeterButton->TabIndex = 1;
			this->CalculatePerimeterButton->Text = L"Периметр";
			this->CalculatePerimeterButton->UseVisualStyleBackColor = false;
			this->CalculatePerimeterButton->Click += gcnew System::EventHandler(this, &MainWindow::CalculatePerimeterButton_Click);
			// 
			// CalculcateCircleAreaButton
			// 
			this->CalculcateCircleAreaButton->BackColor = System::Drawing::Color::LightPink;
			this->CalculcateCircleAreaButton->FlatAppearance->BorderSize = 0;
			this->CalculcateCircleAreaButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CalculcateCircleAreaButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->CalculcateCircleAreaButton->Location = System::Drawing::Point(880, 397);
			this->CalculcateCircleAreaButton->Name = L"CalculcateCircleAreaButton";
			this->CalculcateCircleAreaButton->Size = System::Drawing::Size(152, 57);
			this->CalculcateCircleAreaButton->TabIndex = 1;
			this->CalculcateCircleAreaButton->Text = L"Площа впис. кола";
			this->CalculcateCircleAreaButton->UseVisualStyleBackColor = false;
			this->CalculcateCircleAreaButton->Click += gcnew System::EventHandler(this, &MainWindow::CalculcateCircleAreaButton_Click);
			// 
			// LargestAreaButton
			// 
			this->LargestAreaButton->BackColor = System::Drawing::Color::LightPink;
			this->LargestAreaButton->FlatAppearance->BorderSize = 0;
			this->LargestAreaButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->LargestAreaButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LargestAreaButton->Location = System::Drawing::Point(736, 460);
			this->LargestAreaButton->Name = L"LargestAreaButton";
			this->LargestAreaButton->Size = System::Drawing::Size(297, 57);
			this->LargestAreaButton->TabIndex = 1;
			this->LargestAreaButton->Text = L"Найбільша площа";
			this->LargestAreaButton->UseVisualStyleBackColor = false;
			this->LargestAreaButton->Click += gcnew System::EventHandler(this, &MainWindow::LargestAreaButton_Click);
			// 
			// SortFiguresButton
			// 
			this->SortFiguresButton->BackColor = System::Drawing::Color::LightPink;
			this->SortFiguresButton->FlatAppearance->BorderSize = 0;
			this->SortFiguresButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SortFiguresButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SortFiguresButton->Location = System::Drawing::Point(736, 523);
			this->SortFiguresButton->Name = L"SortFiguresButton";
			this->SortFiguresButton->Size = System::Drawing::Size(297, 57);
			this->SortFiguresButton->TabIndex = 1;
			this->SortFiguresButton->Text = L"Сортування";
			this->SortFiguresButton->UseVisualStyleBackColor = false;
			this->SortFiguresButton->Click += gcnew System::EventHandler(this, &MainWindow::SortFiguresButton_Click);
			// 
			// ScaleFigureButton
			// 
			this->ScaleFigureButton->BackColor = System::Drawing::Color::LightPink;
			this->ScaleFigureButton->FlatAppearance->BorderSize = 0;
			this->ScaleFigureButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ScaleFigureButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ScaleFigureButton->Location = System::Drawing::Point(736, 586);
			this->ScaleFigureButton->Name = L"ScaleFigureButton";
			this->ScaleFigureButton->Size = System::Drawing::Size(297, 57);
			this->ScaleFigureButton->TabIndex = 1;
			this->ScaleFigureButton->Text = L"Масштабування фігури";
			this->ScaleFigureButton->UseVisualStyleBackColor = false;
			this->ScaleFigureButton->Click += gcnew System::EventHandler(this, &MainWindow::ScaleFigureButton_Click);
			// 
			// InformationFigureTextBox
			// 
			this->InformationFigureTextBox->BackColor = System::Drawing::Color::LightPink;
			this->InformationFigureTextBox->Location = System::Drawing::Point(736, 172);
			this->InformationFigureTextBox->Multiline = true;
			this->InformationFigureTextBox->Name = L"InformationFigureTextBox";
			this->InformationFigureTextBox->ReadOnly = true;
			this->InformationFigureTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->InformationFigureTextBox->Size = System::Drawing::Size(297, 219);
			this->InformationFigureTextBox->TabIndex = 2;
			this->InformationFigureTextBox->TextChanged += gcnew System::EventHandler(this, &MainWindow::InformationFigureTextBox_TextChanged);
			// 
			// SaveToFileButton
			// 
			this->SaveToFileButton->BackColor = System::Drawing::Color::LightPink;
			this->SaveToFileButton->FlatAppearance->BorderSize = 0;
			this->SaveToFileButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SaveToFileButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SaveToFileButton->Location = System::Drawing::Point(736, 649);
			this->SaveToFileButton->Name = L"SaveToFileButton";
			this->SaveToFileButton->Size = System::Drawing::Size(138, 59);
			this->SaveToFileButton->TabIndex = 3;
			this->SaveToFileButton->Text = L"Зберегти у файл";
			this->SaveToFileButton->UseVisualStyleBackColor = false;
			this->SaveToFileButton->Click += gcnew System::EventHandler(this, &MainWindow::SaveToFileButton_Click);
			// 
			// LoadFromFileButton
			// 
			this->LoadFromFileButton->BackColor = System::Drawing::Color::LightPink;
			this->LoadFromFileButton->FlatAppearance->BorderSize = 0;
			this->LoadFromFileButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->LoadFromFileButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LoadFromFileButton->Location = System::Drawing::Point(880, 649);
			this->LoadFromFileButton->Name = L"LoadFromFileButton";
			this->LoadFromFileButton->Size = System::Drawing::Size(153, 58);
			this->LoadFromFileButton->TabIndex = 4;
			this->LoadFromFileButton->Text = L"Завантажити з файлу";
			this->LoadFromFileButton->UseVisualStyleBackColor = false;
			this->LoadFromFileButton->Click += gcnew System::EventHandler(this, &MainWindow::LoadFromFileButton_Click);
			// 
			// FigureSelectComboBox
			// 
			this->FigureSelectComboBox->BackColor = System::Drawing::Color::LightPink;
			this->FigureSelectComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->FigureSelectComboBox->FormattingEnabled = true;
			this->FigureSelectComboBox->Location = System::Drawing::Point(736, 138);
			this->FigureSelectComboBox->Name = L"FigureSelectComboBox";
			this->FigureSelectComboBox->Size = System::Drawing::Size(296, 28);
			this->FigureSelectComboBox->TabIndex = 5;
			this->FigureSelectComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::FigureSelectComboBox_SelectedIndexChanged);
			// 
			// DrawingField
			// 
			this->DrawingField->BackColor = System::Drawing::Color::LightPink;
			this->DrawingField->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->DrawingField->Location = System::Drawing::Point(10, 3);
			this->DrawingField->Name = L"DrawingField";
			this->DrawingField->Size = System::Drawing::Size(715, 715);
			this->DrawingField->TabIndex = 0;
			this->DrawingField->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainWindow::DrawingField_Paint);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(144, 144);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(117)));
			this->ClientSize = System::Drawing::Size(1054, 720);
			this->Controls->Add(this->FigureSelectComboBox);
			this->Controls->Add(this->LoadFromFileButton);
			this->Controls->Add(this->SaveToFileButton);
			this->Controls->Add(this->InformationFigureTextBox);
			this->Controls->Add(this->CalculcateCircleAreaButton);
			this->Controls->Add(this->CalculatePerimeterButton);
			this->Controls->Add(this->ScaleFigureButton);
			this->Controls->Add(this->SortFiguresButton);
			this->Controls->Add(this->LargestAreaButton);
			this->Controls->Add(this->ClearFieldButton);
			this->Controls->Add(this->CreateFigureButton);
			this->Controls->Add(this->DrawingField);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MainWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Головне меню";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//Вибір фігури за індексом з комбо бокса
	private: void SelectFigure(int index)
	{
		selected_index = index;

		if (index < 0)
		{
			FigureSelectComboBox->SelectedIndex = 0;
			InformationFigureTextBox->Text = L"";
		}
		else
		{
			FigureSelectComboBox->SelectedIndex = index + 2;
			InformationFigureTextBox->Text = BuildFigureInfo(index);
		}

		DrawingField->Invalidate();
	}

	private: void EnsureFigureSelected()
	{
		if (selected_index == -1)
		{
			throw FigureException(L"Спочатку виберіть фігуру зі списку.");
		}

		if (selected_index == -2)
		{
			throw FigureException(L"Ця дія працює лише з однією конкретною фігурою, а не з «Усі».");
		}
	}

	private: void RefreshFigureList()
	{
		FigureSelectComboBox->Items->Clear();
		FigureSelectComboBox->Items->Add(L"--Виберіть фігуру--");
		FigureSelectComboBox->Items->Add(L"1. Усі");

		int count = manage->getCount();
		for (int i = 0; i < count; i++)
		{
			Figure f = manage->getFigure(i);
			System::String^ label = (i + 2).ToString()+ L". " + ConvertCyrillicToString(f.GetName());
			FigureSelectComboBox->Items->Add(label);
		}

		FigureSelectComboBox->SelectedIndex = 0;
		selected_index = -1;
	}

	private: void ShowError(const FigureException& ex)
	{
		System::String^ msg = gcnew System::String(ex.GetMessage().c_str());
		MessageBox::Show(msg, L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}

	private: System::String^ ConvertCyrillicToString(const std::string& s)
	{
		if (s.empty()) return System::String::Empty;

		array<System::Byte>^ bytes = gcnew array<System::Byte>((int)s.length());
		System::Runtime::InteropServices::Marshal::Copy(
			System::IntPtr((void*)s.c_str()), bytes, 0, (int)s.length());

		return System::Text::Encoding::UTF8->GetString(bytes);
	}

	private: void EnsureNotEmpty()
	{
		if (manage->getCount() == 0) {
			throw FigureException(L"На полі немає жодної фігури!");
		}
	}

	private: System::String^ BuildFigureInfo(int index)
	{
		Figure figure = manage->getFigure(index);
		System::String^ nl = Environment::NewLine;
		System::String^ managedName = ConvertCyrillicToString(figure.GetName());

		System::String^ text = L"Назва: " + managedName + nl;
		text += L"Кількість відрізків: " + figure.GetSegmentsCount().ToString() + nl;
		text += L"Периметр: " + figure.GetPerimeter().ToString(L"F2") + nl;
		text += L"Площа: " + figure.GetArea().ToString(L"F2") + nl;

		try {
			text += L"Площа вписаного кола: " + figure.areaOfInscribedCircle().ToString(L"F2") + nl;
		}
		catch (FigureException& ex) {
			text += gcnew System::String(ex.GetMessage().c_str()) + nl;
		}

		text += L"Макс. кількість фігур із цієї к-сті відрізків: " + figure.maxFiguresBySegments().ToString() + nl;
		text += L"Відрізки (x0; y0) - (x1; y1):" + nl;

		for (int j = 0; j < figure.GetSegmentsCount(); j++) {
			Segment s = figure.GetSegment(j);
			PointSegment a = s.getStart();
			PointSegment b = s.getEnd();
			text += (j + 1).ToString() + L": (" + a.x.ToString(L"F1") + L"; " + a.y.ToString(L"F1")
				+ L") - (" + b.x.ToString(L"F1") + L"; " + b.y.ToString(L"F1") + L")" + nl;
		}
		return text;
	}
	
	//Поле, де будуть відображатися фігури
	private: System::Void DrawingField_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		e->Graphics->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

		Pen^ pen = gcnew Pen(Color::Black, 2);
		Pen^ selectedPen = gcnew Pen(Color::PaleVioletRed, 3);

		int count = manage->getCount();
		int fieldHeight = DrawingField->ClientSize.Height;

		for (int i = 0; i < count; i++)
		{
			Figure figure = manage->getFigure(i);
			int segCount = figure.GetSegmentsCount();

			bool isSelected = (selected_index == -2) || (selected_index == i);
			Pen^ current_pen = isSelected ? selectedPen : pen;

			for (int j = 0; j < segCount; j++)
			{
				Segment s = figure.GetSegment(j);
				PointSegment p1 = s.getStart();
				PointSegment p2 = s.getEnd();

				e->Graphics->DrawLine(current_pen, p1.x, fieldHeight - p1.y, p2.x, fieldHeight - p2.y);
			}
		}
	}

	private: System::Void ClearFieldButton_Click(System::Object^ sender, System::EventArgs^ e) {
		manage->clearAll();
		RefreshFigureList();
		DrawingField->Invalidate();
	}

	private: System::Void CreateFigureButton_Click(System::Object^ sender, System::EventArgs^ e) {
		CreateFigureForm^ form = gcnew CreateFigureForm();
		System::Windows::Forms::DialogResult result = form->ShowDialog();

		if (result == System::Windows::Forms::DialogResult::OK)
		{
			try
			{
				manage->addFigureToList(form->GetResultFigure());
				RefreshFigureList();
				DrawingField->Invalidate();
			}
			catch (FigureException& ex)
			{
				System::String^ msg = gcnew System::String(ex.GetMessage().c_str());
				MessageBox::Show(msg, L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
		delete form;
	}
	
	private: System::Void CalculatePerimeterButton_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			EnsureFigureSelected();
			Figure f = manage->getFigure(selected_index);
			InformationFigureTextBox->Text = L"Периметр фігури «"
				+ ConvertCyrillicToString(f.GetName()) + L"»: "
				+ f.GetPerimeter().ToString(L"F2");
		}
		catch (FigureException& ex) {
			ShowError(ex);
		}
	}

	private: System::Void CalculcateCircleAreaButton_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			EnsureFigureSelected();
			Figure f = manage->getFigure(selected_index);
			InformationFigureTextBox->Text = L"Площа вписаного кола фігури «"
				+ ConvertCyrillicToString(f.GetName()) + L"»: "
				+ f.areaOfInscribedCircle().ToString(L"F2");
		}
		catch (FigureException& ex) {
			ShowError(ex);
		}
	}

	private: System::Void LargestAreaButton_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			EnsureNotEmpty();
			int index = manage->findLargestAreaWithFewestSegments();
			SelectFigure(index);
			InformationFigureTextBox->Text = L"Найбільша площа (серед таких - найменше відрізків):"
				+ Environment::NewLine + InformationFigureTextBox->Text;
		}
		catch (FigureException& ex) {
			ShowError(ex);
		}
	}

	private: System::Void SortFiguresButton_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			EnsureNotEmpty();
			manage->sortByPerimeter();
			SelectFigure(-1);   // порядок змінився - старий індекс більше недійсний

			System::String^ text = L"Фігури за зростанням периметра:" + Environment::NewLine;
			for (int i = 0; i < manage->getCount(); i++) {
				Figure f = manage->getFigure(i);
				text += (i + 1).ToString() + L". "
					+ ConvertCyrillicToString(f.GetName())
					+ L" - P = " + f.GetPerimeter().ToString(L"F2") + Environment::NewLine;
			}
			InformationFigureTextBox->Text = text;
		}
		catch (FigureException& ex) {
			ShowError(ex);
		}
	}
	
	private: System::Void ScaleFigureButton_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			EnsureFigureSelected();

			EnterScaleWindow^ dialog = gcnew EnterScaleWindow();
			if (dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				manage->scaleFigure(selected_index, dialog->getFactor());
				SelectFigure(selected_index);   // оновити малюнок і інформацію
			}
			delete dialog;
		}
		catch (FigureException& ex) {
			ShowError(ex);
		}
	}

	private: System::Void SaveToFileButton_Click(System::Object^ sender, System::EventArgs^ e) {
		SaveFileDialog^ dialog = gcnew SaveFileDialog();
		dialog->Filter = L"Текстові файли (*.txt)|*.txt|Усі файли (*.*)|*.*";

		if (dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			try {
				manage->saveToFile(msclr::interop::marshal_as<std::wstring>(dialog->FileName));
				MessageBox::Show(L"Фігури збережено.", L"Готово", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			catch (FigureException& ex) {
				ShowError(ex);
			}
		}
		delete dialog;
	}

	private: System::Void LoadFromFileButton_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ dialog = gcnew OpenFileDialog();
		dialog->Filter = L"Текстові файли (*.txt)|*.txt|Усі файли (*.*)|*.*";

		if (dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			try {
				manage->loadFromFile(msclr::interop::marshal_as<std::wstring>(dialog->FileName));
				SelectFigure(-1);
			}
			catch (FigureException& ex) {
				ShowError(ex);
			}
		}
		delete dialog;
	}

	private: System::Void InformationFigureTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void FigureSelectComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		int combo = FigureSelectComboBox->SelectedIndex;

		if (combo <= 0)
		{
			selected_index = -1;  // плейсхолдер
		}
		else if (combo == 1)
		{
			selected_index = -2;  // "Усі"
		}
		else
		{
			selected_index = combo - 2;  // конкретна фігура, 0-базований індекс у manager
		}

		DrawingField->Invalidate();
	}
};
}
