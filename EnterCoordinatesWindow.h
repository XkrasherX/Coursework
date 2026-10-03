#pragma once

/*
це вікно не створюється через WindowsForm, 
бо наперед невідомо скільки відрізків буде у фігури.
У вікні CreateFigureWindow спочатку вказується назва і к-ть відрізків,
а вже тут створюється необхідна кількість текстбоксів для введення координат кожного відрізку
*/

#include "Figure.h"
#include "FigureException.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

public ref class EnterCoordinatesWindow : public System::Windows::Forms::Form
{
public:
    //Головне вікно для заповнення даних
    EnterCoordinatesWindow(System::String^ name, int segmentsCount)
    {
        figureName = name;
        rowCount = segmentsCount;
        resultFigure = nullptr;

        this->Text = L"Координати відрізків";
        this->AutoScroll = true;
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
        this->MaximizeBox = false;
        this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
        this->BackColor = System::Drawing::Color::Pink;
        BuildRows();
    }

    //геттер  результату заповнення координат точок відрізка
    Figure GetResultFigure()
    {
        return *resultFigure;
    }

protected:
    //деструктор
    ~EnterCoordinatesWindow()
    {
        delete resultFigure;
        resultFigure = nullptr;
    }

private:
    System::String^ figureName; //назва фігури
    int rowCount; //кількість відрізків
    Figure* resultFigure;  //результуючий клас, який зберігає дані про фігуру(координати)

    array<TextBox^>^ x0Boxes; //масив для збереження координат першої точки відрізку по X
    array<TextBox^>^ y0Boxes; //масив для збереження координат першої точки відрізку по Y
    array<TextBox^>^ x1Boxes; //масив для збереження координат другої точки відрізку по X
    array<TextBox^>^ y1Boxes; //масив для збереження координат другої точки відрізку по Y

    //функція для побудови рядків і стовпців
    void BuildRows()
    {
        //параметри елементів
        const int margin = 10; // зовнішній відступ
        const int gap = 8; //відстань між елементами
        const int rowHeight = 23; //висота рядка
        const int labelWidth = 200; //ширина надпису
        const int textBoxWidth = 50; //ширина текстового поля
        const int buttonWidth = 140; //ширина кнопки
        const int buttonHeight = 30; //висота кнопки

        //створюємо масиви для коодинаь
        x0Boxes = gcnew array<TextBox^>(rowCount);
        y0Boxes = gcnew array<TextBox^>(rowCount);
        x1Boxes = gcnew array<TextBox^>(rowCount);
        y1Boxes = gcnew array<TextBox^>(rowCount);

        int y = margin; //відступ від краю форми для початку створення елементів

        // заголовки колонок X0 Y0 X1 Y1
        array<System::String^>^ headers = { 
            L"X0",
            L"Y0",
            L"X1",
            L"Y1" };

        int headerX = margin + labelWidth + gap;
        for (int i = 0; i < 4; i++)
        {
            Label^ header = gcnew Label();
            header->Text = headers[i];
            header->Location = System::Drawing::Point(headerX, y);
            header->Size = System::Drawing::Size(textBoxWidth, rowHeight);
            this->Controls->Add(header);
            headerX += textBoxWidth + gap;
        }

        //змістити відступ для наступного рядка
        y += rowHeight + gap;

        // один рядок на відрізок
        for (int i = 0; i < rowCount; i++)
        {
            //створення рядка для відрізку
            Label^ rowLabel = gcnew Label();
            rowLabel->Text = L"Введіть координати відрізку №" + (i + 1).ToString();
            rowLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            rowLabel->Location = System::Drawing::Point(margin, y);
            rowLabel->Size = System::Drawing::Size(labelWidth, rowHeight);
            this->Controls->Add(rowLabel);

            //відступ по Х для створення текстбоксів для запису координат
            int xPos = margin + labelWidth + gap;

            //створення текстбокс для Х0
            x0Boxes[i] = gcnew TextBox();
            x0Boxes[i]->Location = System::Drawing::Point(xPos, y);
            x0Boxes[i]->Size = System::Drawing::Size(textBoxWidth, rowHeight);
            this->Controls->Add(x0Boxes[i]);
            this->x0Boxes[i]->BackColor = System::Drawing::Color::LightPink;
            this->x0Boxes[i]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            xPos += textBoxWidth + gap;

            //створення текстбокс для Y0
            y0Boxes[i] = gcnew TextBox();
            y0Boxes[i]->Location = System::Drawing::Point(xPos, y);
            y0Boxes[i]->Size = System::Drawing::Size(textBoxWidth, rowHeight);
            this->Controls->Add(y0Boxes[i]);
            this->y0Boxes[i]->BackColor = System::Drawing::Color::LightPink;
            this->y0Boxes[i]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            xPos += textBoxWidth + gap;

            //створення текстбокс для Х1
            x1Boxes[i] = gcnew TextBox();
            x1Boxes[i]->Location = System::Drawing::Point(xPos, y);
            x1Boxes[i]->Size = System::Drawing::Size(textBoxWidth, rowHeight);
            this->Controls->Add(x1Boxes[i]);
            this->x1Boxes[i]->BackColor = System::Drawing::Color::LightPink;
            this->x1Boxes[i]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            xPos += textBoxWidth + gap;

            //створення текстбокс для Y1
            y1Boxes[i] = gcnew TextBox();
            y1Boxes[i]->Location = System::Drawing::Point(xPos, y);
            y1Boxes[i]->Size = System::Drawing::Size(textBoxWidth, rowHeight);
            this->Controls->Add(y1Boxes[i]);
            this->y1Boxes[i]->BackColor = System::Drawing::Color::LightPink;
            this->y1Boxes[i]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;

            //відступ вниз для створення наступного рядка
            y += rowHeight + gap;
        }

        //кнопка для створення фігури 
        Button^ CreateButton = gcnew Button();
        CreateButton->Text = L"Створити фігуру";
        CreateButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(204)));
        CreateButton->Location = System::Drawing::Point(margin, y);
        CreateButton->Size = System::Drawing::Size(buttonWidth, buttonHeight);
        CreateButton->Click += gcnew System::EventHandler(this, &EnterCoordinatesWindow::CreateButtonFigure_Click);
        CreateButton->BackColor = System::Drawing::Color::LightPink;
        CreateButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;

        this->Controls->Add(CreateButton);

        //кнопка для скасування дії
        Button^ CanceButton = gcnew Button();
        CanceButton->Text = L"Скасувати";
        CanceButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(204)));
        CanceButton->Location = System::Drawing::Point(margin + buttonWidth + gap, y);
        CanceButton->Size = System::Drawing::Size(buttonWidth, buttonHeight);
        CanceButton->Click += gcnew System::EventHandler(this, &EnterCoordinatesWindow::CanceButton_Click);
        CanceButton->BackColor = System::Drawing::Color::LightPink;
        CanceButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->Controls->Add(CanceButton);

        //відступ від кнопки до краю форми
        y += buttonHeight + gap; 

        //ширина форми
        int formWidth = 2 * margin + labelWidth + 4 * gap + 4 * textBoxWidth;

        //заповнення розмірами ширини і висоти форми
        this->ClientSize = System::Drawing::Size(formWidth, y);
    }

    //перевірка на коректність вводу координат
    float ParseCoordinate(System::String^ text)
    {
        float value;
        System::String^ normalized = text->Trim(); //відкидає пробіли 
        normalized = normalized->Replace(L',', L'.'); //замінює коми на крапку
        
        //перевірка на коректність координати
        bool ok = Single::TryParse(normalized,
            System::Globalization::NumberStyles::Float,
            System::Globalization::CultureInfo::InvariantCulture, value);

        if (!ok)
        {
            throw FigureException(L"Координата повинна бути числом.");
        }
        return value;
    }

    //кнопка для створення фігури
    System::Void CreateButtonFigure_Click(System::Object^ sender, System::EventArgs^ e)
    {
        try
        {
            //створення відрізку за координатами
            Segment* segs = new Segment[rowCount];

            //цикл для коректного вводу координат у масив з відрізками
            for (int i = 0; i < rowCount; i++)
            {
                float x0 = ParseCoordinate(x0Boxes[i]->Text);
                float y0 = ParseCoordinate(y0Boxes[i]->Text);
                float x1 = ParseCoordinate(x1Boxes[i]->Text);
                float y1 = ParseCoordinate(y1Boxes[i]->Text);

                segs[i] = Segment(x0, y0, x1, y1);
            }

            //конвертація кирилиці
            array<System::Byte>^ nameBytes = System::Text::Encoding::UTF8->GetBytes(figureName);
            std::string nativeName(reinterpret_cast<char*>(System::Runtime::InteropServices::Marshal::UnsafeAddrOfPinnedArrayElement(nameBytes, 0).ToPointer()), nameBytes->Length);

            //заповнення класу даними з координатами
            if (resultFigure != nullptr) {
                delete resultFigure;
                resultFigure = nullptr;
            }
            resultFigure = new Figure(nativeName, segs, rowCount);

            delete[] segs;

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
    System::Void CanceButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
        this->Close();
    }
};