#include <iostream>

using namespace std;

// struktura listy
struct lista_element
{
    int nr;
    lista_element *next;

    // konstruktor struktury
    lista_element(int wartosc)
    {
        nr = wartosc;
        next = NULL;
    }
};

class Lista
{
public:
    lista_element *glowa;

    // konstruktor klasy
    Lista()
    {
        glowa = NULL; // ustawianie na null
    }

    void dodawanie(int numerek) // F dodawania el
    {
        lista_element *nowy = new lista_element(numerek); // tworzenie nowego el

        if (glowa == NULL)
        {
            glowa = nowy;
        }
        else
        {
            // dodawanie el z racji ze jest null to sprawdzamy ostatni el przed null
            lista_element *temp = glowa;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = nowy;
        }
    }

    int usuwanie_ostatni_el() // F usuwania ostatniego el
    {
        // sprawdzenie czy lista jest pusta
        if (glowa == NULL)
        {
            cout << "Lista jest pusta!" << endl;
            return -1;
        }

        if (glowa->next == NULL)
        {
            int usunietawartosc = glowa->nr;
            delete glowa;
            glowa = NULL;
            return usunietawartosc;
        }

        // usuwanie ostatniego el przed null i zwrocenie go
        lista_element *temp = glowa;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        int usunietawartosc = temp->next->nr;
        delete temp->next;
        temp->next = NULL;

        return usunietawartosc;
    }

    void wypisz() // F wypisujaca liste
    {
        lista_element *temp = glowa;
        while (temp != NULL)
        {
            cout << temp->nr << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Lista mojaLista;

    // poczatkowe el
    mojaLista.dodawanie(10);
    mojaLista.dodawanie(20);
    mojaLista.dodawanie(30);

    int liczba;

    while (true)
    {
        cout << "\n1.Wypisz" << endl;
        cout << "2.Dodaj" << endl;
        cout << "3.Usun ostatni element" << endl;
        cout << "0.Wyjdz" << endl;
        cout << "podaj wybor: ";
        cin >> liczba;

        switch (liczba)
        {
        case 1:
            mojaLista.wypisz();
            break;

        case 2:
        {
            int numerek;
            cout << "Wpisz numer: ";
            cin >> numerek;
            mojaLista.dodawanie(numerek);
            break;
        }

        case 3:
            cout << "Usunieto: " << mojaLista.usuwanie_ostatni_el() << endl;
            break;

        case 0:
            return 0;

        default:
            cout << "Zly wybor!" << endl;
            break;
        }
    }

    return 0;
}
