#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
int j = 0;
vector<vector<string>> slots;
class ParkingEntry
{
    vector<int> empty_slots;

public:
    ParkingEntry(int n = 10)
    {
        for (size_t i = 0; i < n; i++)
            empty_slots.push_back(i); // as initially all slots are empty.
        for (int i = 0; i < 3; i++)
            slots.push_back(vector<string>()); // Add an empty row
    }

    void park(string n, string clr, int l) // park car of particular color = clr  and number = n at nearest slot.
    {
        if (j < l)
        {
            int nearest = *min_element(empty_slots.begin(), empty_slots.end()); // nearest available slot obtained
            slots[0].push_back(clr);
            slots[1].push_back(n);
            slots[2].push_back(to_string(nearest));
            auto it = find(empty_slots.begin(), empty_slots.end(), nearest);
            int index = it - empty_slots.begin();
            empty_slots.erase(empty_slots.begin() + index);
            cout << "Your car is parked at slot number " << nearest + 1 << endl;
            j++;
        }
        else
            cout << "Sorry...Lot is full!\n";
    }
    void unpark(string n)
    {
        bool car_was_present = false;
        int i;
        for (i = 0; i < j; i++)
        {
            if (n.compare(slots[1][i]) == 0)
            {
                slots[0].erase(slots[0].begin() + i);
                slots[1].erase(slots[1].begin() + i);
                cout << "Your car is unparked!\n";
                car_was_present = true;
                j--;
                break;
            }
        }
        if (car_was_present)
            empty_slots.push_back(i);
        else
            cout << "Oops!..No such car present.\n";
    }
};
class Details
{
public:
    void findCar(string reg, int slot_number, bool flag)
    {
        bool found = false;
        for (size_t i = 0; i < j; i++)
        {
            if (flag == true)
            {
                if (reg.compare(slots[1][i]) == 0)
                {
                    cout << "Car colour is : " << slots[0][i] << endl;
                    cout << "Slot number is : " << stoi(slots[2][i]) + 1 << endl;
                    found = true;
                    break;
                }
            }
            else
            {
                if (to_string(slot_number - 1).compare(slots[2][i]) == 0)
                {
                    cout << "Car number is : " << slots[1][i] << endl;
                    cout << "Car colour is : " << slots[0][i] << endl;
                    found = true;
                    break;
                }
            }
        }
        if (found == false)
        {
            cout << "Oops!..No such slot found.\n";
        }
    }
    void findByClr(string clr)
    {
        bool found = false;
        cout << "Registration number\t\tSlot\n";
        for (size_t i = 0; i < j; i++)
        {
            if (clr.compare(slots[0][i]) == 0)
            {
                cout << slots[1][i] << "\t\t\t\t" << stoi(slots[2][i]) + 1 << "\n";
                found = true;
            }
        }
        if (found == false)
        {
            cout << "Oops!..No such cars found.\n";
        }
    }
};
int main(int argc, char *argv[])
{
    string filename = argv[1];
    string ext = filename.substr(filename.length() - 3);
    if (ext.compare("txt") == 0)
    {
    }
    else
    {
        int n, res;
        cout << "Enter capacity of Parking lot : ";
        cin >> n;
        ParkingEntry obj(n);
        Details ob;
        do
        {
            cout << "\n1.Park car.\n";
            cout << "2.Unpark car.\n";
            cout << "3.Find slot.\n";
            cout << "4.Find car number.\n";
            cout << "5.Find car.\n";
            cout << "Enter your choice : ";
            cin >> res;
            string reg, clr;
            if (res == 1)
            {
                cout << "\nEnter car number : ";
                cin >> reg;
                cout << "\nEnter car colour : ";
                cin >> clr;
                obj.park(reg, clr, n);
            }
            else if (res == 2)
            {
                cout << "\nEnter car number : ";
                cin >> reg;
                obj.unpark(reg);
            }
            else if (res == 3)
            {
                int slot;
                cout << "\nEnter slot number : ";
                cin >> slot;
                ob.findCar("", slot, false);
            }
            else if (res == 4)
            {
                cout << "\nEnter car number : ";
                cin >> reg;
                ob.findCar(reg, 0, true);
            }
            else if (res == 5)
            {
                cout << "\nEnter car colour : ";
                cin >> clr;
                ob.findByClr(clr);
            }
        } while (res != 0);
    }
    cout << "Thank You\n";
    return 0;
}