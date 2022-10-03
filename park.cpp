#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;
int j = 0;
class ParkingEntry
{
protected:
    vector<vector<string>> slots;
    vector<int> empty_slots;
    int nearestSlot(vector<int> empty)
    {
        return min_element(empty.begin(), empty.end()) - empty.begin();
    }

public:
    ParkingEntry(int n = 10)
    {
        for (size_t i = 0; i < n; i++)
        {
            empty_slots.push_back(i); // as initially all slots are empty.
        }
    }
    void park(string n = "", string clr = "") // park car of particular color = clr  and number = n at nearest slot.
    {
        int nearest = nearestSlot(empty_slots); // nearest available slot obtained
        slots[0].push_back(clr);
        slots[1].push_back(n);
        slots[2].push_back(to_string(nearest));
        auto it = find(empty_slots.begin(), empty_slots.end(), nearest);
        int index = it - empty_slots.begin();
        empty_slots.erase(empty_slots.begin() + index);
        j++;
    }
    void unpark(string n, string clr)
    {
        bool car_was_present = false;
        int i;
        for (i = 0; i < j; i++)
        {
            if (clr.compare(slots[0][i]) == 0 && n.compare(slots[1][i]) == 0)
            {
                slots[0].erase(slots[0].begin() + i);
                slots[1].erase(slots[1].begin() + i);
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
class Details : public ParkingEntry
{
    bool found = false;

public:
    void findCar(string reg, int slot_number, bool flag)
    {
        found = false;
        for (size_t i = 0; i <= j; i++)
        {
            if (flag)
            {
                if (reg.compare(slots[1][i]) == 0)
                {
                    cout << "Car colour is : " << slots[0][i] << endl;
                    cout << "Slot number is : " << stoi(slots[3][i]) << endl;
                    found = true;
                    break;
                }
            }
            else
            {
                if (to_string(slot_number).compare(slots[2][i]) == 0)
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
        found = false;
        cout << "Registration number\t\tSlot\n";
        for (size_t i = 0; i <= j; i++)
        {
            if (clr.compare(slots[0][i]) == 0)
            {
                cout << slots[1][i] << "\t\t" << stoi(slots[2][i]) << "\n";
                found = true;
                break;
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
    string extension = filename.substr(filename.length() - 4);
    if (extension.compare("txt")) // file operation
    {
    }
    else
    {
        if (strcmp(argv[1], "create_parking_lot") == 0)
        {
            int n = stoi(argv[2]);
            ParkingEntry obj(n);
            for (size_t i = 3; i < argc;)
            {
                if (argv[i] == "park")
                {
                    obj.park(argv[i + 1], argv[i + 2]);
                    i += 3;
                }
                else if (argv[i] == "unpark")
                {
                    obj.unpark(argv[i + 1], argv[i + 2]);
                    i += 3;
                }
                else if (argv[i] == "find_parking_slot")
                {
                    Details ob;
                    ob.findCar("", stoi(argv[i + 1]), false);
                    i += 2;
                }
                else if (argv[i] == "find_car_number")
                {
                    Details ob;
                    ob.findCar(argv[i + 1], 0, true);
                    i += 2;
                }
                else if (argv[i] == "find_car")
                {
                    Details ob;
                    ob.findByClr(argv[i + 1]);
                    i += 2;
                }
                else
                {
                    cout << "Error : Entered command is inappropriate\n";
                    break;
                }
            }
        }
        else
            cout << "Error : Inappropriate command or Parking Lot not created\n";
    }
    return 0;
}