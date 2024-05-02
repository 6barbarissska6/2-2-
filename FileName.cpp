#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

struct Node {

    int val;
    Node* next;
    Node* prev;
    Node(int _val) :val(_val), next(nullptr), prev(nullptr) {} // ����������� ����, ���������������� �������� ���� _val � ��������������� ��������� next � prev � nullptr.

};

struct list
{
    Node* first;
    Node* last;
    list() : first(nullptr), last(nullptr) {} // ����������� ������, ���������������� ��������� first � last � nullptr.

    bool is_empty()
    {
        return(first == nullptr);
    }
    void pushBack(int _val) {
        Node* ptr = new Node(_val);
        if (is_empty()) {
            first = ptr;
            last = ptr;
            return;
        }
        last->next = ptr; // ���� ������ �� ����, ������������� ��������� next ���������� ���� �� ����� ����,
         ptr->prev = last; //������������� ��������� prev ������ ����
         last = ptr; //�� ��������� ����, � ����� ��������� ��������� last �� ����� ����.*/
       
        
    }
    void push(int _val, int ind) {
        if (is_empty()) {
            pushBack(_val);
            return;
        }
        Node* ptr = new Node(_val);
        Node* cur = first;
        for (int i = 0; i < ind - 1; i++) {
            cur = cur->next;
        }
        ptr->next = cur->next;
        cur->next->prev = ptr;
        ptr->prev = cur;
        cur->next = ptr;

    }
    void printForward() {
        if (is_empty()) {
            cout << "������ ����. ������ ����������." << std::endl;
            return;
        }
        Node* ptr = first;
        while (ptr) {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }


    void removeFirst() {
        if (is_empty()) {
            std::cout << "������ ����. �������� ����������." << std::endl;
            return;
        }
        Node* ptr = first;
        first = ptr->next;
        first->prev = nullptr;
        delete ptr;
    }

    void removeLast() {
        if (is_empty()) {
            std::cout << "������ ����. �������� ����������." << std::endl;
            return;
        }
        Node* ptr = last;
        last = ptr->prev;
        last->next = nullptr;
        delete ptr;
    }
    void removeVal(int _val) {
        if (is_empty()) {
            cout << "������ ����. �������� ����������." << std::endl;
            return;
        }
        if (first->val == _val) {
            removeFirst();
            return;
        }
        if (last->val == _val) {
            removeLast();
            return;
        }
        Node* slow = first;
        Node* fast = slow->next;
        while (fast && fast->val != _val) {
            slow = fast;
            fast = fast->next;
        }
        if (!fast) {
            std::cout << "��� ������� ����������� � ������." << std::endl;
            return;
        }
        slow->next = fast->next;
        fast->next->prev = slow;
        delete fast;
        std::cout << "������� �����. ����� ������:" << std::endl;
        printForward();
    }

    void removeInd(int ind)
    {
        if (is_empty()) {
            cout << "������ ����. �������� ����������." << endl;
            return;
        }
        if (ind == 0)
        {
            removeFirst();
            return;
        }
        Node* cur = first;
        for (int i = 0; i < ind; i++)
        {

            cur = cur->next;

        }
        if (!cur)
        {
            cout << "������ ����� �� ������� ������.�������� ����������" << endl;
            return;
        }
        if (cur->next == nullptr)
        {
            cur->prev->next = nullptr;
            delete cur;
            cout << "������� ������.����� ������: " << endl;
            printForward();
            return;

        }
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        cout << "������� ������.����� ������:" << endl;
        printForward();


    }

    void swap(int ind1, int ind2) {
        if (is_empty()) {
            cout << "������ ����." << endl;
            return;
        }
        if (first == last) {
            return;
        }
        Node* t1 = first;
        for (int i = 0; i < ind1; i++) {
            if (t1->next == nullptr) {
                cout << "������ " << ind1 << " ������� �� ������� ������." << endl;
                return;
            }
            t1 = t1->next;
        }
        Node* t2 = first;
        for (int i = 0; i < ind2; i++) {
            if (t2->next == nullptr) {
                cout << "������ " << ind2 << " ������� �� ������� ������." << endl;
                return;
            }
            t2 = t2->next;
        }
        Node* val1 = new Node(t1->val);
        Node* val2 = new Node(t2->val);
        t1->val = val2->val;
        t2->val = val1->val;
        delete val1;
        delete val2;
        cout << "�������� �������� �������. ����� ������:" << endl;
        printForward();
    }

    void get_val(int _val)
    {
        if (is_empty()) {
            cout << "������ ����." << endl;
            return;
        }
        int ind = 0;
        Node* ptr = first;
        do
        {
            if (ptr->val == _val)
            {
                cout << "������ �����:" << ind;
                return;

            }
            ind++;
            ptr = ptr->next;



        } while (ptr->next != nullptr);

        cout << "������ �������� ��� � ������" << endl;


    }

    void get_ind(int ind)
    {
        if (is_empty()) {
            cout << "������ ����." << endl;
            return;
        }
        Node* ptr = first;
        int test = 0;
        for (int i = 0; i < ind; i++) {
            if (ptr->next != nullptr) {
                ptr = ptr->next;
                test += 1;
            }
        }
        if (test != ind) {
            cout << "��� ������ ������� �� ������� ������." << endl;
            return;
        }
        cout << "�������� �� ������ ������� - " << ptr->val << "." << endl;
    }






};





list task1a();
list task1b();
list task1();
list task3(list l);
list bublesort(list l);
int* createDynArr();

int main()
{
    setlocale(0, "");
    srand(time(0));
    list l;
    int tnum;


    do
    {

        cout << " ������� ����� �������:" << endl;
        cout <<" 1. ������������ ����������� ������ ����������� N, ���:" << endl;
        cout <<" a) ������������ ������ ���������� ��������� � ������, ������� ����� ������������� ����������� ���������� �������(0 �� 99);" << endl;
        cout <<" �) ������������ ������ � ������� �������� ������, N ������������ ������������� �� ���������� ��������� ���������;" << endl;
        cout <<" 2. ����������� �������� �������� ����������� ������ �. 2." << endl;
        cout <<" 3. �������, ��������, ����� � ��������� �������� ����������� ������. �������� � ��������� �������� ���������� ����������� �� ������� � �� ��������." << endl;
        cout <<" 4. ����������� �������� �������, �������� � ��������� �������� ����������� ������ �. 3." << endl;
        cout <<" 5. ��� �1 � ���������� �������." << endl;
        cout <<" 6. ��� �1 � ������������ ��������." << endl;
        cout <<" 0. �����. " << endl;
        cin >> tnum;
        switch (tnum)
        {
        case 1:
            l = task1();
            break;

        case 2:
            l = task1();
            break;

        case 3:
            task3(l);
            break;

        case 4:
            task3(l);
            break;
        case 5:
            bublesort(l);
            break;
        case 6:
            int* arr = createDynArr();
            delete[] arr;
            break;
        }


    } while (tnum);
    return 0;


}


list task1()
{

    list l;
    int num;
    cout << "�������� ��� ���������� ������: (1-���� 2-�������): " << endl;
    cin >> num;
    switch (num)
    {
    case 1:
        l = task1a();
        break;
    case 2:
        l = task1b();
        break;


    }

    return l;


}

list task1a()
{

    list l_a;
    cout << "������� ���-�� ��������� � ������:";
    int size;
    cin >> size;
    auto start = system_clock::now(); //
    for (int i = 0; i < size; i++) {
        l_a.pushBack(rand() % 99);
    }
    auto end = system_clock::now(); //
    auto result = duration_cast<nanoseconds>(end - start); //
    cout << "����� ����������� �� �������� ����������� ������ - " << result.count() << " ����������." << endl; //
    cout << "������� ������:" << endl;
    l_a.printForward();
    return l_a;


}

list task1b()
{
    list l_b;
    cout << "������� �������� ������:" << endl;
    int val;
    int amount = 0; //
    do {
        cin >> val;
        auto start = system_clock::now(); //
        l_b.pushBack(val);
        auto end = system_clock::now(); //
        auto result = duration_cast<nanoseconds>(end - start); //
        amount += result.count(); //
    } while (val != 0);
    cout << "����� ����������� �� �������� ����������� ������ - " << amount << " ����������." << endl; //
    cout << "������� ������:" << endl;
    l_b.printForward();
    return l_b;
}

list task3(list l) {
    int count;
    do {
        cout << "�������� �������� (1 - �������; 2 - ��������; 3 - �����; 4 - ���������; 0 - ���������): ";
        cin >> count;
        if (count == 1) {
            int number;
            cout << "������� �����: ";
            cin >> number;
            auto start1 = system_clock::now(); //
            l.pushBack(number);
            auto end1 = system_clock::now(); //
            auto result1 = duration_cast<nanoseconds>(end1 - start1); //
            cout << "����� ����������� �� ������� - " << result1.count() << " ����������." << endl; //
            cout << "����� " << number << " ��������� � ����� ������. ����� ������:" << endl;
            l.printForward();
        }
        else if (count == 2) {
            cout << "�������� �������� (1 - �������� �� �������; 2 - �������� �� ��������): ";
            int count2;
            cin >> count2;
            if (count2 == 1) {
                int ind;
                cout << "������� ������ (��������� ���������� � 0): ";
                cin >> ind;
                auto start21 = system_clock::now(); //
                l.removeInd(ind);
                auto end21 = system_clock::now(); //
                auto result21 = duration_cast<nanoseconds>(end21 - start21); //
                cout << "����� ����������� �� �������� - " << result21.count() << " ����������." << endl; //
            }
            else if (count2 == 2) {
                int val;
                cout << "������� ��������: ";
                cin >> val;
                auto start22 = system_clock::now(); //
                l.removeVal(val);
                auto end22 = system_clock::now(); //
                auto result22 = duration_cast<nanoseconds>(end22 - start22); //
                cout << "����� ����������� �� �������� - " << result22.count() << " ����������." << endl; //
            }
        }
        else if (count == 3) {
            cout << "������� ������� (��������� ���������� � 0): ";
            int ind1, ind2;
            cin >> ind1;
            cin >> ind2;
            auto start3 = system_clock::now(); //
            l.swap(ind1, ind2);
            auto end3 = system_clock::now(); //
            auto result3 = duration_cast<nanoseconds>(end3 - start3); //
            cout << "����� ����������� �� ����� - " << result3.count() << " ����������." << endl; //
            cout << "����� ������:" << endl;
            l.printForward();
        }
        else if (count == 4) {
            cout << "�������� �������� (1 - ��������� �� �������; 2 - ��������� �� ��������): ";
            int count4;
            cin >> count4;
            if (count4 == 1) {
                int ind;
                cout << "������� ������ (��������� ���������� � 0): ";
                cin >> ind;
                auto start41 = system_clock::now(); //
                l.get_ind(ind);
                auto end41 = system_clock::now(); //
                auto result41 = duration_cast<nanoseconds>(end41 - start41); //
                cout << "����� ����������� �� ��������� - " << result41.count() << " ����������." << endl; //
            }
            else if (count4 == 2) {
                int val;
                cout << "������� ��������: ";
                cin >> val;
                auto start42 = system_clock::now(); //
                l.get_val(val);
                auto end42 = system_clock::now(); //
                auto result42 = duration_cast<nanoseconds>(end42 - start42); //
                cout << "����� ����������� �� ��������� - " << result42.count() << " ����������." << endl; //
            }
        }
    } while (count == 1 || count == 2 || count == 3 || count == 4);
    return l;
}

//IDZ


list bublesort(list l)
{


    list l_a;
    cout << "������� ���-�� ��������� � ������:";
    int size;

    cin >> size;
    for (int i = 0; i < size; i++) {
        l_a.pushBack(rand() % 99);
    }



    Node* left = l_a.first;
    Node* right = l_a.first->next;



    auto start = system_clock::now(); //

    while (left->next) {
        while (right) {
            if ((left->val) > (right->val)) {
                swap(left->val, right->val);

            }
            right = right->next;

        }
        left = left->next;
        right = left->next;



    }



    /*  for (int i=0; i <size-1; i++)
      {
          Node* ptr1 = l_a.first;
          for (int j = 0; j < size -i- 1; j++)
          {

              if (ptr1->val > ptr1->next->val)
                 l_a.swap(i,j );
              ptr1 = ptr1->next;


          }
          ptr = ptr->next;

      }*/

    auto end = system_clock::now(); //
    auto result = duration_cast<nanoseconds>(end - start); //
    cout << "����� ����������� �� ���������� ����������� ������ - " << result.count() << " ����������." << endl; //
    cout << "������� ������:" << endl;
    l_a.printForward();
    return l_a;



}



int* createDynArr() {
    int size = 0;
    int* arr = new int[size];



    cout << "������� ���������� ��������� � �������: ";
    cin >> size;
    int* rez = new int[size];
    arr = rez;
    for (int i = 0; i < size; i++) {
        *(arr + i) = rand() % 99;
    }

    auto start = system_clock::now(); //


    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // ������ �������� �������
                swap(arr[j], arr[j + 1]);
            }
        }
    }


    auto end = system_clock::now(); //
    auto result = duration_cast<nanoseconds>(end - start); //
    cout << "����� ����������� �� ���������� ������������� ������� - " << result.count() << " ����������." << endl; //


    // ����� ���������������� ������� �� �����
    cout << "����� ������:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    return arr;

}
/* if (act == 2) {
    cout << "������� �������� �������:" << endl;
    int val;
    auto start = system_clock::now(); //
    while (cin >> val) {
        size += 1;
        int* rez = new int[size];
        for (int i = 0; i < size - 1; i++) {
            rez[i] = arr[i];
        }
        delete[] arr;
        arr = rez;
        *(arr + size - 1) = val;
    }
    cout << "����� ������:" << endl;
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    �out << endl;
    delete[] arr;
    auto end = system_clock::now(); //
    auto result = duration_cast<nanoseconds>(end - start); //
    cout << "����� ����������� �� ���������� ������������� ������� - " << result.count() << " ����������." << endl; //


}
return arr; */