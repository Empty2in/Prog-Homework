#include <iostream>
#include "base-types.h"
#include "CompositeShape.h"
#include "Concave.h"
#include "Rectangle.h"
#include "Shape.h"
#include <fstream>

const int SIZE = 20;
void sortShape(const int& size, Shape** arr);
Shape* isRectangle(std::istream& stream);
Shape* isConcave(std::istream& stream);
Shape* isComposite(std::istream& stream);
bool isPoint(std::istream& stream, point_t& pt);
bool isDouble(std::istream& stream, double& k);
void outputArray(Shape** arr, const int& size);
void badComposite(std::string& compShape, std::istream& stream);


int main()
{
    std::cout << "The program start\n\n";
    std::ifstream in;
    std::string shape;
    std::string fileName;
    point_t scalePt;
    double moveX = 0,
           moveY = 0,
           scaleK = 0;
    bool flagMove = true, 
         flagScalePt = true, 
         flagScaleK = true;

    int numOfShape = 0;
    Shape* arr[SIZE]{ nullptr };
 
    std::cout << "  Enter filename: ";
    std::cin >> fileName;
    try
    {
        in.open(fileName);
        if (!in.is_open())
        {
            throw std::exception("fail couldn't be open");
        }

        while (!in.eof())
        {
            shape = "";
            in >> shape;
            if (shape == "RECTANGLE")
            {
                arr[numOfShape] = isRectangle(in);
                if (arr[numOfShape] != nullptr)
                {
                    numOfShape++;
                }

            }
            else if (shape == "CONCAVE")
            {
                arr[numOfShape] = isConcave(in);
                if (arr[numOfShape] != nullptr)
                {
                    numOfShape++;
                }
            }
            else if (shape == "COMPLEX")
            {
                arr[numOfShape] = isComposite(in);
                if (arr[numOfShape] != nullptr)
                {
                    numOfShape++;
                }

            }
            else if (shape == "SCALE")
            {
                if (!isPoint(in, scalePt))
                {
                    flagScalePt = false;
                }
                if (!isDouble(in, scaleK) || scaleK <= 0)
                {
                    flagScaleK = false;
                }
                in.ignore();
            }
            else if (shape == "MOVE")
            {
                if (!isDouble(in, moveX))
                {
                    flagMove = false;
                }
                if (!isDouble(in, moveY))
                {
                    flagMove = false;
                }
                in.ignore();
            }
            else
            {
                getline(in, shape, '\n');
                continue;
            }
        }
        if (numOfShape == 0)
        {
            throw std::exception("unknown figures found in the file");
        }
        else
        {
            std::cout << "\n\t\t\t\tTesting sort function\n" << "  Array befor sorting:\n";
            outputArray(arr, numOfShape);
            sortShape(numOfShape, arr);
            std::cout << "  Array after sorting:\n";
            outputArray(arr, numOfShape);
        }
        std::cout << "\n-----------------------------------------\n\n";

        std::cout << "\t\t\t\tTesting scale shapes\n";
        if (flagScalePt && flagScaleK)
        {
            std::cout << "  Array befor scale:\n";
            outputArray(arr, numOfShape);
            for (int i = 0; i < numOfShape; i++)
            {
                arr[i]->scale(scalePt, scaleK);
            }
            std::cout << "  Array after scale:\n";
            outputArray(arr, numOfShape);
        }
        else
        {
            if (!flagScalePt)
            {
                std::cerr << "The scale point is set incorrectly." << "\n";
            }
            if (!flagScaleK)
            {
                std::cerr << "The scale coefficient is set incorrectly." << "\n";
            }
        }
        std::cout << "\n-----------------------------------------\n\n";
   
        std::cout << "\t\t\t\tTesting move shapes\n";
        if (flagMove)
        {
            std::cout<< "  Array befor move:\n";
            outputArray(arr, numOfShape);
            for (int i = 0; i < numOfShape; i++)
            {
                arr[i]->move(moveX, moveY);
            }
            std::cout << "  Array after move:\n";
            outputArray(arr, numOfShape);
        }
        else
        {
            std::cerr << "The coordinates of the movement are set uncorrectly, the Move method cannot be applied" << "\n";
        }
        std::cout << "\n-----------------------------------------\n\n";

        CompositeShape compose(numOfShape);
        for (int i = 0; i < numOfShape; i++)
        {
            compose.addShape(i, arr[i]);
        }

        std::cout << "\t\t\t\tTesting constructor of copy\n\n";
        CompositeShape copyComp(compose);
        std::cout << "  First CompositShape: " << &compose;
        std::cout << "  Second CompositShape: " << &copyComp;
        std::cout << "\n-----------------------------------------\n\n";

        std::cout << "\t\t\t\tTesting constructor of move\n\n" << "  Composite befor moving:\n";
        std::cout << &compose;
        CompositeShape moveComp = compose;
        std::cout << "  Composite after moving:\n" << &moveComp;
        std::cout << "\n-----------------------------------------\n\n";

        std::cout << "The end of the program";
    }
    catch (const std::exception& e)
    {
        std::cout << "ERROR: " << e.what() << "\n";
        exit(-1);
    }
    in.close();

	return 0;
}

void sortShape(const int& size, Shape** arr)
{
    for (int i = 1; i < size; ++i) {
        Shape* temp = arr[i];
        int j = i;
        while (j > 0 && *temp < *arr[j - 1]) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = temp;
    }
}
Shape* isRectangle(std::istream& stream)
{
    point_t pt_1, pt_2;
    if (!isPoint(stream, pt_1))
    {
        std::cerr << "The Rectangle is set uncorrectly." << "\n";
        return nullptr;
    }
    if (!isPoint(stream, pt_2))
    {
        std::cerr << "The Rectangle is set uncorrectly." << "\n";
        return nullptr;
    }
    stream.ignore();
    Rectangle rect(pt_1, pt_2);
    if (!rect.checkRectangle())
    {
        std::cerr << "These points don't form a rectaingle.";
        return nullptr;
    }
    return rect.clone();
}
Shape* isConcave(std::istream& stream)
{
    point_t pt_1, pt_2, pt_3, pt_4;
    if (!isPoint(stream, pt_1))
    {
        std::cerr << "The Concave is set uncorrectly." << "\n";
        return nullptr;
    }
    if (!isPoint(stream, pt_2))
    {
        std::cerr << "The Concave is set uncorrectly." << "\n";
        return nullptr;
    }
    if (!isPoint(stream, pt_3))
    {
        std::cerr << "The Concave is set uncorrectly." << "\n";
        return nullptr;
    }
    if (!isPoint(stream, pt_4))
    {
        std::cerr << "The Concave is set uncorrectly." << "\n";
        return nullptr;
    }
    stream.ignore();
    Concave conc(pt_1, pt_2, pt_3, pt_4);
    if (!conc.checkConcave())
    {
        std::cerr << "This shape can't be concave." << "\n";
        return nullptr;
    }
    return conc.clone();

}
Shape* isComposite(std::istream& stream)
{
    std::string compShape;
    int count = 0, index = 0;
    bool theEnd = false;
    stream >> count;
    if (stream.fail() || stream.peek() != '\n')
    {
        stream.clear();
        stream.sync();
        badComposite(compShape, stream);
        return nullptr;
    }
    if (count <= 0)
    {
        std::cerr << "Uncorrect size of composite.";
        stream.clear();
        stream.sync();
        badComposite(compShape, stream);
        return nullptr;
    }
    CompositeShape compose(count);
    stream.ignore();
    for (int i = 0; i < count; i++)
    {
        compShape = "";
        stream >> compShape;
        if (compShape == "RECTANGLE")
        {
            compose.addShape(index, isRectangle(stream));
            index++;
        }
        else if (compShape == "CONCAVE")
        {
            compose.addShape(index, isConcave(stream));
            index++;
        }
        else if (compShape == "COMPOSITE")
        {
            compose.addShape(index, isComposite(stream));
            index++;

        }
        else if (compShape == "COMPLEXEND")
        {
            theEnd = true;
            break;
        }
        else
        {
            getline(stream, compShape, '\n');
            continue;
        }
    }
    if (!theEnd)
    { 
        stream >> compShape;
    }
    if (compShape != "COMPLEXEND")
    {
        while (compShape != "COMPLEXEND")
        {
            if (stream.eof())
            {
                throw std::exception("the end of CompositeShape not founded");
            }
            getline(stream, compShape, '\n');
        }
        return nullptr;
    }
    compose.newSize(index);
    return compose.clone();
}
void badComposite(std::string& compShape, std::istream& stream)
{
    while (compShape != "COMPLEXEND")
    {
        if (stream.eof())
        {
            throw std::exception("the end of CompositeShape not founded");
        }
        getline(stream, compShape, '\n');
    }
}
void outputArray(Shape** arr, const int& size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i];
    }
}
bool isDouble(std::istream& stream, double& k)
{
    if (stream.peek() == '\n')
    {
        return false;
    }
    stream >> k;
    if (stream.fail())
    {
        stream.clear();
        stream.sync();
        return false;
    }
    return true;
}
bool isPoint(std::istream& stream, point_t& pt)
{
    if (!(isDouble(stream, pt.x)))
    {
        return false;
    }
    if (!(isDouble(stream, pt.y)))
    {
        return false;
    }
    return true;
}
