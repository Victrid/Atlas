#include <iostream>

using namespace std;

template <typename T>
struct uzel {
    uzel<T>* next;
    uzel<T>* last;
    T value;
    uzel(T& nos) {
        last  = nullptr;
        next  = nullptr;
        value = nos;
    }
    uzel() {
        last = nullptr;
        next = nullptr;
    }
};

template <typename T>
class linlist {

    template <typename Ty>
    friend linlist<Ty> operator+(linlist<Ty>& lin1, linlist<Ty>& lin2);
    template <typename Ty>
    friend ostream& operator<<(ostream& os, const linlist<Ty>& l);

private:
    uzel<T>* start;
    uzel<T>* end;

public:
    linlist<T>* operator+=(T var) {
        uzel<T>* temp   = new uzel<T>(var);
        end->last->next = temp;
        end->last       = temp;
        temp->next      = end;
        return this;
    }
    linlist() {
        start       = new uzel<T>;
        end         = new uzel<T>;
        start->next = end;
        end->last   = start;
    }
    linlist(linlist<T>& l) {
        start       = new uzel<T>;
        end         = new uzel<T>;
        start->next = end;
        end->last   = start;
        for (uzel<T>* ptr = l.start->next; ptr != l.end; ptr = ptr->next) {
            *this += ptr->value;
        }
    }
};

template <typename T>
ostream& operator<<(ostream& os, const linlist<T>& l) {
    uzel<T>* ptr = l.start->next;
    while (ptr != l.end) {
        if (ptr != l.start->next)
            os << ' ';
        os << ptr->value;
        ptr = ptr->next;
    }
    return os;
}

template <typename T>
linlist<T> operator+(linlist<T>& lin1, linlist<T>& lin2) {
    linlist<T> ans(lin1);
    for (uzel<T>* ptr = lin2.start->next; ptr != lin2.end; ptr = ptr->next)
        ans += ptr->value;
    return ans;
}

template <typename T>
void process() {
    int n, m;
    cin >> n >> m;
    T proc;
    linlist<T> lin1, lin2;
    for (int i = 0; i < n; i++) {
        cin >> proc;
        lin1 += proc;
    }

    for (int i = 0; i < m; i++) {
        cin >> proc;
        lin2 += proc;
    }

    cout << (lin1 + lin2);
}

int main() {
    char type[7];
    cin >> type;
    switch (type[0]) {
    case 'd':
        process<double>();
        break;
    case 'c':
        process<char>();
        break;
    case 'i':
        process<int>();
    }
    return 0;
}