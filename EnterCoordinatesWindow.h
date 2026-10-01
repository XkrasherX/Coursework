#pragma once
#include <msclr/marshal_cppstd.h>
#include <vector>

#include "Figure.h"
#include "FigureException.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace msclr::interop;

// Це вікно НЕ використовує Windows Forms Designer - весь інтерфейс
// (рядки з полями) генерується кодом, бо кількість рядків заздалегідь
// невідома (залежить від кількості відрізків, введеної у вікні 2).
// Тому додай цей файл як звичайний Header File (Add -> New Item -> Header File),
// а НЕ через майстер "Windows Form".
public ref class EnterCoordinatesWindow : public System::Windows::Forms::Form
{
public:
    EnterCoordinatesWindow(System::String^ name, int segmentsCount)
    {
        figureName = name;
        rowCount = segmentsCount;
        resultFigure = nullptr;

        this->Text = L"Координати відрізків";
        this->AutoScroll = true;  // про всяк випадок, якщо відрізків буде дуже багато
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
        this->MaximizeBox = false;
        this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;

        BuildRows();
    }

    Figure GetResultFigure()
    {
        return *resultFigure;
    }

protected:
    ~EnterCoordinatesWindow()
    {
        delete resultFigure;
    }

private:
    System::String^ figureName;
    int rowCount;
    Figure* resultFigure;  // нативний клас - тримаємо через вказівник (ref class не може містити його за значенням)

    array<TextBox^>^ x0Boxes;
    array<TextBox^>^ y0Boxes;
    array<TextBox^>^ x1Boxes;
    array<TextBox^>^ y1Boxes;

    void BuildRows()
    {
        const int margin = 10;
        const int gap = 8;  // "буквально пару пікселей" - між рядками і від кнопок до краю форми
        const int rowHeight = 23;
        const int labelWidth = 200;
        const int textBoxWidth = 50;
        const int buttonWidth = 140;
        const int buttonHeight = 30;

        x0Boxes = gcnew array<TextBox^>(rowCount);
        y0Boxes = gcnew array<TextBox^>(rowCount);
        x1Boxes = gcnew array<TextBox^>(rowCount);
        y1Boxes = gcnew array<TextBox^>(rowCount);

        int y = margin;

        // заголовки колонок X0 Y0 X1 Y1 - один раз, над усіма рядками
        array<System::String^>^ headers = { L"X0", L"Y0", L"X1", L"Y1" };
        int headerX = margin + labelWidth + gap;
        for (int h = 0; h < 4; h++)
        {
            Label^ header = gcnew Label();
            header->Text = headers[h];
            header->Location = System::Drawing::Point(headerX, y);
            header->Size = System::Drawing::Size(textBoxWidth, rowHeight);
            this->Controls->Add(header);
            headerX += textBoxWidth + gap;
        }
        y += rowHeight + gap;

        // один рядок на відрізок
        for (int i = 0; i < rowCount; i++)
        {
            Label^ rowLabel = gcnew Label();
            rowLabel->Text = L"Введіть координати відрізку №" + (i + 1).ToString();
            rowLabel->Location = System::Drawing::Point(margin, y);
            rowLabel->Size = System::Drawing::Size(labelWidth, rowHeight);
            this->Controls->Add(rowLabel);

            int xPos = margin + labelWidth + gap;

            x0Boxes[i] = gcnew TextBox();
            x0Boxes[i]->Location = System::Drawing::Point(xPos, y);
            x0Boxes[i]->Size = System::Drawing::Size(textBoxWidth, rowHeight);
            this->Controls->Add(x0Boxes[i]);
            xPos += textBoxWidth + gap;

            y0Boxes[i] = gcnew TextBox();
            y0Boxes[i]->Location = System::Drawing::Point(xPos, y);
            y0Boxes[i]->Size = System::Drawing::Size(textBoxWidth, rowHeight);
            this->Controls->Add(y0Boxes[i]);
            xPos += textBoxWidth + gap;

            x1Boxes[i] = gcnew TextBox();
            x1Boxes[i]->Location = System::Drawing::Point(xPos, y);
            x1Boxes[i]->Size = System::Drawing::Size(textBoxWidth, rowHeight);
            this->Controls->Add(x1Boxes[i]);
            xPos += textBoxWidth + gap;

            y1Boxes[i] = gcnew TextBox();
            y1Boxes[i]->Location = System::Drawing::Point(xPos, y);
            y1Boxes[i]->Size = System::Drawing::Size(textBoxWidth, rowHeight);
            this->Controls->Add(y1Boxes[i]);

            y += rowHeight + gap;
        }

        // кнопки - одразу під останнім рядком
        Button^ btnCreate = gcnew Button();
        btnCreate->Text = L"Створити фігуру";
        btnCreate->Location = System::Drawing::Point(margin, y);
        btnCreate->Size = System::Drawing::Size(buttonWidth, buttonHeight);
        btnCreate->Click += gcnew System::EventHandler(this, &EnterCoordinatesWindow::btnCreateFigure_Click);
        this->Controls->Add(btnCreate);

        Button^ btnCancelButton = gcnew Button();
        btnCancelButton->Text = L"Скасувати";
        btnCancelButton->Location = System::Drawing::Point(margin + buttonWidth + gap, y);
        btnCancelButton->Size = System::Drawing::Size(buttonWidth, buttonHeight);
        btnCancelButton->Click += gcnew System::EventHandler(this, &EnterCoordinatesWindow::btnCancel_Click);
        this->Controls->Add(btnCancelButton);

        y += buttonHeight + gap;  // той самий gap - відступ від кнопок до нижнього краю форми

        int formWidth = 2 * margin + labelWidth + 4 * gap + 4 * textBoxWidth;
        this->ClientSize = System::Drawing::Size(formWidth, y);
    }

    float ParseCoordinate(System::String^ text)
    {
        float value;
    System::String^ normalized = text->Trim()->Replace(L',', L'.');
    bool ok = Single::TryParse(normalized,
        System::Globalization::NumberStyles::Float,
        System::Globalization::CultureInfo::InvariantCulture, value);

    if (!ok)
    {
        throw FigureException(L"Координата повинна бути числом.");
    }
    return value;
    }

    System::Void btnCreateFigure_Click(System::Object^ sender, System::EventArgs^ e)
    {
        try
        {
            Segment* segs = new Segment[rowCount];

            for (int i = 0; i < rowCount; i++)
            {
                float x0 = ParseCoordinate(x0Boxes[i]->Text);
                float y0 = ParseCoordinate(y0Boxes[i]->Text);
                float x1 = ParseCoordinate(x1Boxes[i]->Text);
                float y1 = ParseCoordinate(y1Boxes[i]->Text);

                segs[i] = Segment(x0, y0, x1, y1);
            }

            System::String^ nameCopy = figureName;
            std::string nativeName = marshal_as<std::string>(nameCopy);

            delete resultFigure;
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

    System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
        this->Close();
    }
};