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
			selectedIndex = -1;
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
	private: int selectedIndex;
	private: System::Windows::Forms::Panel^ DrawingField;
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
			this->CalculatePerimeterButton = (gcnew System::Windows::Forms::Button());
			this->CalculcateCircleAreaButton = (gcnew System::Windows::Forms::Button());
			this->LargestAreaButton = (gcnew System::Windows::Forms::Button());
			this->SortFiguresButton = (gcnew System::Windows::Forms::Button());
			this->ScaleFigureButton = (gcnew System::Windows::Forms::Button());
			this->InformationFigureTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SaveToFileButton = (gcnew System::Windows::Forms::Button());
			this->LoadFromFileButton = (gcnew System::Windows::Forms::Button());
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
			this->CreateFigureButton->Location = System::Drawing::Point(755, 12);
			this->CreateFigureButton->Name = L"CreateFigureButton";
			this->CreateFigureButton->Size = System::Drawing::Size(258, 57);
			this->CreateFigureButton->TabIndex = 1;
			this->CreateFigureButton->Text = L"Створити фігуру";
			this->CreateFigureButton->UseVisualStyleBackColor = true;
			this->CreateFigureButton->Click += gcnew System::EventHandler(this, &MainWindow::CreateFigureButton_Click);
			// 
			// ClearFieldButton
			// 
			this->ClearFieldButton->Location = System::Drawing::Point(755, 75);
			this->ClearFieldButton->Name = L"ClearFieldButton";
			this->ClearFieldButton->Size = System::Drawing::Size(258, 57);
			this->ClearFieldButton->TabIndex = 1;
			this->ClearFieldButton->Text = L"Очистити поле";
			this->ClearFieldButton->UseVisualStyleBackColor = true;
			this->ClearFieldButton->Click += gcnew System::EventHandler(this, &MainWindow::ClearFieldButton_Click);
			// 
			// CalculatePerimeterButton
			// 
			this->CalculatePerimeterButton->Location = System::Drawing::Point(755, 341);
			this->CalculatePerimeterButton->Name = L"CalculatePerimeterButton";
			this->CalculatePerimeterButton->Size = System::Drawing::Size(119, 57);
			this->CalculatePerimeterButton->TabIndex = 1;
			this->CalculatePerimeterButton->Text = L"Периметр";
			this->CalculatePerimeterButton->UseVisualStyleBackColor = true;
			this->CalculatePerimeterButton->Click += gcnew System::EventHandler(this, &MainWindow::CalculatePerimeterButton_Click);
			// 
			// CalculcateCircleAreaButton
			// 
			this->CalculcateCircleAreaButton->Location = System::Drawing::Point(895, 341);
			this->CalculcateCircleAreaButton->Name = L"CalculcateCircleAreaButton";
			this->CalculcateCircleAreaButton->Size = System::Drawing::Size(118, 57);
			this->CalculcateCircleAreaButton->TabIndex = 1;
			this->CalculcateCircleAreaButton->Text = L"Площа впис. кола";
			this->CalculcateCircleAreaButton->UseVisualStyleBackColor = true;
			this->CalculcateCircleAreaButton->Click += gcnew System::EventHandler(this, &MainWindow::CalculcateCircleAreaButton_Click);
			// 
			// LargestAreaButton
			// 
			this->LargestAreaButton->Location = System::Drawing::Point(755, 404);
			this->LargestAreaButton->Name = L"LargestAreaButton";
			this->LargestAreaButton->Size = System::Drawing::Size(258, 57);
			this->LargestAreaButton->TabIndex = 1;
			this->LargestAreaButton->Text = L"Найбільша площа";
			this->LargestAreaButton->UseVisualStyleBackColor = true;
			this->LargestAreaButton->Click += gcnew System::EventHandler(this, &MainWindow::LargestAreaButton_Click);
			// 
			// SortFiguresButton
			// 
			this->SortFiguresButton->Location = System::Drawing::Point(755, 467);
			this->SortFiguresButton->Name = L"SortFiguresButton";
			this->SortFiguresButton->Size = System::Drawing::Size(258, 57);
			this->SortFiguresButton->TabIndex = 1;
			this->SortFiguresButton->Text = L"Сортування";
			this->SortFiguresButton->UseVisualStyleBackColor = true;
			this->SortFiguresButton->Click += gcnew System::EventHandler(this, &MainWindow::SortFiguresButton_Click);
			// 
			// ScaleFigureButton
			// 
			this->ScaleFigureButton->Location = System::Drawing::Point(755, 530);
			this->ScaleFigureButton->Name = L"ScaleFigureButton";
			this->ScaleFigureButton->Size = System::Drawing::Size(258, 57);
			this->ScaleFigureButton->TabIndex = 1;
			this->ScaleFigureButton->Text = L"Масштабування фігури";
			this->ScaleFigureButton->UseVisualStyleBackColor = true;
			this->ScaleFigureButton->Click += gcnew System::EventHandler(this, &MainWindow::ScaleFigureButton_Click);
			// 
			// InformationFigureTextBox
			// 
			this->InformationFigureTextBox->BackColor = System::Drawing::Color::Bisque;
			this->InformationFigureTextBox->Location = System::Drawing::Point(755, 138);
			this->InformationFigureTextBox->Multiline = true;
			this->InformationFigureTextBox->Name = L"InformationFigureTextBox";
			this->InformationFigureTextBox->ReadOnly = true;
			this->InformationFigureTextBox->Size = System::Drawing::Size(258, 197);
			this->InformationFigureTextBox->TabIndex = 2;
			// 
			// SaveToFileButton
			// 
			this->SaveToFileButton->Location = System::Drawing::Point(758, 603);
			this->SaveToFileButton->Name = L"SaveToFileButton";
			this->SaveToFileButton->Size = System::Drawing::Size(254, 51);
			this->SaveToFileButton->TabIndex = 3;
			this->SaveToFileButton->Text = L"Зберегти у файл";
			this->SaveToFileButton->UseVisualStyleBackColor = true;
			this->SaveToFileButton->Click += gcnew System::EventHandler(this, &MainWindow::SaveToFileButton_Click);
			// 
			// LoadFromFileButton
			// 
			this->LoadFromFileButton->Location = System::Drawing::Point(760, 660);
			this->LoadFromFileButton->Name = L"LoadFromFileButton";
			this->LoadFromFileButton->Size = System::Drawing::Size(253, 49);
			this->LoadFromFileButton->TabIndex = 4;
			this->LoadFromFileButton->Text = L"Завантажити з файлу";
			this->LoadFromFileButton->UseVisualStyleBackColor = true;
			this->LoadFromFileButton->Click += gcnew System::EventHandler(this, &MainWindow::LoadFromFileButton_Click);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1054, 734);
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
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: void ShowError(const FigureException& ex)
	{
		System::String^ msg = gcnew System::String(ex.GetMessage().c_str());
		MessageBox::Show(msg, L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}

	private: void EnsureFigureSelected()
	{
		if (selectedIndex < 0 || selectedIndex >= manage->getCount()) {
			throw FigureException(L"Спочатку оберіть фігуру, клікнувши по ній на полі!");
		}
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

		System::String^ text = L"Назва: " + msclr::interop::marshal_as<System::String^>(figure.GetName()) + nl;
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

	private: void SelectFigure(int index)
	{
		selectedIndex = index;
		if (index >= 0) {
			InformationFigureTextBox->Text = BuildFigureInfo(index);
		}
		else {
			InformationFigureTextBox->Text = L"";
		}
		DrawingField->Invalidate();
	}
	//Поле, де будуть відображатися фігури
	private: System::Void DrawingField_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		e->Graphics->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

		Pen^ pen = gcnew Pen(Color::Black, 2);
		Pen^ selectedPen = gcnew Pen(Color::Red, 3);
		int count = manage->getCount();

		for (int i = 0; i < count; i++) {
			Figure figure = manage->getFigure(i);
			int segment_count = figure.GetSegmentsCount();
			Pen^ currentPen = (i == selectedIndex) ? selectedPen : pen;

			for (int j = 0; j < segment_count; j++) {
				Segment segment = figure.GetSegment(j);
				PointSegment p1 = segment.getStart();
				PointSegment p2 = segment.getEnd();
				e->Graphics->DrawLine(currentPen, p1.x, p1.y, p2.x, p2.y);
			}

			// підпис фігури біля її першої вершини
			if (segment_count > 0) {
				PointSegment first = figure.GetSegment(0).getStart();
				System::String^ title = msclr::interop::marshal_as<System::String^>(figure.GetName());
				e->Graphics->DrawString(title, this->Font, Brushes::Black, first.x + 4, first.y + 4);
			}
		}
	}

	private: System::Void DrawingField_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		int index = manage->findFigureAt((float)e->X, (float)e->Y);
		SelectFigure(index);
	}

	private: System::Void ClearFieldButton_Click(System::Object^ sender, System::EventArgs^ e) {
		manage->clearAll();
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
				SelectFigure(manage->getCount() - 1);   // нова фігура одразу вибрана
			}
			catch (FigureException& ex)
			{
				ShowError(ex);
			}
		}
		delete form;
	}
	

	private: System::Void CalculatePerimeterButton_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			EnsureFigureSelected();
			Figure f = manage->getFigure(selectedIndex);
			InformationFigureTextBox->Text = L"Периметр фігури «"
				+ msclr::interop::marshal_as<System::String^>(f.GetName()) + L"»: "
				+ f.GetPerimeter().ToString(L"F2");
		}
		catch (FigureException& ex) {
			ShowError(ex);
		}
	}

	private: System::Void CalculcateCircleAreaButton_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			EnsureFigureSelected();
			Figure f = manage->getFigure(selectedIndex);
			InformationFigureTextBox->Text = L"Площа вписаного кола фігури «"
				+ msclr::interop::marshal_as<System::String^>(f.GetName()) + L"»: "
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
					+ msclr::interop::marshal_as<System::String^>(f.GetName())
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
				manage->scaleFigure(selectedIndex, dialog->Factor);
				SelectFigure(selectedIndex);   // оновити малюнок і інформацію
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
};
}
