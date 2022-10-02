#include <iostream>
#include <string>
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
    void park(int sl = 0, string n = "", string clr = "") // park car of particular color = clr  and number = n at particular slot = s1
    {
        int nearest = nearestSlot(empty_slots); // nearest available slot obtained
        slots[0][nearest] = clr;
        slots[1][nearest] = n;
        slots[2][nearest] = to_string(sl);
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
    string No, color;
    bool found = false;

public:
    Details(string n = "", string clr = "")
    {
        No = n;
        color = clr;
    }
    void showReg(string clr)
    {
        cout << "Registration number :- \n";
        for (size_t i = 0; i <= j; i++)
        {
            if (clr.compare(slots[0][i]) == 0)
            {
                cout << slots[2][i] << "\n";
                found = true;
            }
        }
        cout << "\n";
        if (found == false)
            cout << "Oops!..No such car present.\n";
    }
    void slot(string reg)
    {
        found = false;
        for (size_t i = 0; i <= j; i++)
        {
            if (reg.compare(slots[1][i]) == 0)
            {
                cout << "Found slot is : " << stoi(slots[3][i]) << endl;
                found = true;
                break;
            }
        }
        if (found == false)
        {
            cout << "Oops!..No such slot found.\n";
        }
    }
    void allSlots(string clr)
    {
        found = false;
        cout << "Registration number\t\tSlot\n";
        for (size_t i = 0; i <= j; i++)
        {
            if (clr.compare(slots[0][i]) == 0)
            {
                cout << slots[2][i] << "\t\t" << stoi(slots[3][i]) << "\n";
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
    string extension = filename.substr(filename.length() - 4);
    do
    {
        if (extension == "txt") // file operation
        {
        }
        else
        {
            if(argv[1]=="create_parking_lot")
            {
                int n = stoi(argv[2]);
                ParkingEntry obj(n);

            }
            else
                cout << "Error : Inappropriate command or Parking Lot not created\n";
        }
    }while(true);
    return 0;
}
