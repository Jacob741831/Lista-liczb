#include <iostream>

using namespace std;

// struktura listy
struct lista_element
{
    int nr;
    lista_element *next; // wskaŸnik na kolejny element

    // konstruktor struktury
    lista_element(int wartosc)
    {
        nr = wartosc;
        next = NULL; // domyœlnie nastêpny to null
    }
};

class Lista
{
public:
    lista_element *glowa; // wskaŸnik na pocz¹tek listy

    // konstruktor klasy
    Lista()
    {
        glowa = NULL; // na pocz¹tku lista jest pusta
    }

    void dodawanie(int numerek) // dodaje na sam koniec listy
    {
        lista_element *nowy = new lista_element(numerek);

        if (glowa == NULL)
        {
            glowa = nowy;
        }
        else
        {
            lista_element *temp = glowa;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = nowy;
        }
    }

    int usuwanie_ostatni_el() // funkcja usuwa ostatni el z listy i go zwraca
    {
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

    void wypisz() // funkcja wypisuje liste
    {
        if (glowa == NULL)
        {
            cout << "Lista jest pusta!" << endl;
            return;
        }

        lista_element *temp = glowa;
        while (temp != NULL)
        {
            cout << temp->nr << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    Lista mojaLista; // obiekt klasy Lista

    // Ogarniêta basickowa lista na start (dodajemy przyk³adowe dane)
    mojaLista.dodawanie(10);
    mojaLista.dodawanie(20);
    mojaLista.dodawanie(30);

    int liczba;

    // Zloopowany switch - pêtla dzia³a ca³y czas, dopóki u¿ytkownik nie wybierze 0
    while (true)
    {
        cout << "\n==========================" << endl;
        cout << "1. Wypisz" << endl;
        cout << "2. Dodaj" << endl;
        cout << "3. Usun ostatni element" << endl;
        cout << "0. Wyjdz z programu" << endl;
        cout << "==========================" << endl;
        cout << "podaj wybor: ";
        cin >> liczba;

        cout << endl;

        // pole wyboru typu liczbowego
        switch (liczba)
        {
        case 1:
            cout << "Zawartosc listy: ";
            mojaLista.wypisz();
            break;

        case 2:
        {
            int numerek;
            cout << "Wpisz numer ktory chcesz dodac: ";
            cin >> numerek;
            mojaLista.dodawanie(numerek);
            cout << "Dodano " << numerek << " do listy." << endl;
            break;
        }

        case 3:
        {
            int usuniety = mojaLista.usuwanie_ostatni_el();
            if (usuniety != -1)
            {
                cout << "Usuniêto element: " << usuniety << endl;
            }
            break;
        }

        case 0:
            cout << "Koniec programu!" << endl;
            return 0; // wyjœcie z programu

        default:
            cout << "Wprowadz z listy wyboru!" << endl;
            break;
        }
    }

    return 0;
}
