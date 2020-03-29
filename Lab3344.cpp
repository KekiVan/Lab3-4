#include <iostream>
using namespace std;


class CycleListElement
{
    public:
        int Field; // Значение элемента списка
        struct CycleListElement* Pointer; // Указатель на следующий элемент списка
        bool IsHead;


        CycleListElement* FindPreHead()
        {
            CycleListElement* iterator = this->Pointer;
            while (!iterator->Pointer->IsHead)
            {
                iterator = iterator->Pointer;
            }
            return iterator;
		}

        CycleListElement* FindPrevious(bool outputFlag)
        {
            CycleListElement* iterator = this->Pointer;

            if (outputFlag)
            {
                cout << this->Field << " ";
			}

            while (iterator != this)
            {
                if (outputFlag)
                {
                    cout << iterator->Field << " ";
                }

                iterator = iterator->Pointer;
            }
            return iterator;
		}


        CycleListElement(int elementValue, CycleListElement* previousElement, bool ToHead)
        {
            Field = elementValue;
            IsHead = false;
            if (ToHead)
            {
                IsHead = true;
                previousElement = previousElement->FindPreHead();
                previousElement->Pointer->IsHead = false;
			}
            if (previousElement != NULL)
            {
                Pointer = previousElement->Pointer;
                previousElement->Pointer = this;
            }
            else
            {
                Pointer = this;
                IsHead = true;
			}
        }

        
        ~CycleListElement()
        {
            FindPrevious(false)->Pointer = Pointer;
        }
        
};

/*
struct CycleList* Init(int elementValue) // а- значение первого узла
{
    CycleList* NewList;
    // выделение памяти под корень списка
    NewList = (CycleList*)malloc(sizeof(CycleList));
    NewList->Field = elementValue;
    NewList->Pointer = NewList; // указатель на сам корневой узел
    return(NewList);
}

struct CycleList* AddElement(CycleList* previousElement, int newElementValue)
{
    CycleList newElement;
    
    



 
    temp = (CycleList*)malloc(sizeof(CycleList));
    p = lst->Pointer; // сохранение указателя на следующий элемент
    lst->Pointer = temp; // предыдущий узел указывает на создаваемый
    temp->Field = elementValue; // сохранение поля данных добавляемого узла
    temp->Pointer = p; // созданный узел указывает на следующий элемент
    return(temp);
}

void listprint(list* lst)
{
    struct list* p;
    p = lst;
    do {
        printf("%d ", p->field); // вывод значения узла p
        p = p->ptr; // переход к следующему узлу
    } while (p != lst); // условие окончания обхода
}
*/
int main()
{
    CycleListElement* object = new CycleListElement(10, NULL, false);
    object->FindPrevious(true);
    cout << "\n";
    for (int i = object->Field - 1; i >= 0; i--)
    {
        new CycleListElement(i, object, true);
        object->FindPreHead()->Pointer->FindPrevious(true);
        cout << "\n";
    }

    return 0;
}