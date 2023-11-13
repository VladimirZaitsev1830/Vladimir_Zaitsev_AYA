#include <iostream>
#include <list>
#include <string>
#include <cmath>

using namespace std;


struct element_t
{
    int type;
    int code;
    double val;
};





void udalenie(list<element_t> &test)
{
    auto ind1 = test.begin();
    auto ind2 = test.begin();
    ind2++;
    ind2++;
    while(ind2 != test.end())
    {
        if ((ind1->type == 1) && (ind1->code == 1) && (ind2->type == 1) && (ind2->code == 2))
        {
            ind1 = test.erase(ind1);
            ind1--;
            ind2 = test.erase(ind2);
        }
        else
        {
            ind1++;
            ind2++;
        }


    }
}















void skobki(list<element_t> &test)
{
    auto per = test.begin();
    auto vtor = test.begin();
    auto tret = test.begin();
    double ch1;
    double ch2;
    element_t sim;
    while ((per->type != 1) || (per->code != 2))
    {
        per++;
        vtor++;
        tret++;
    }
    while ((vtor->type != 1) || (vtor->code != 1))
    {
        vtor--;
    }
    while ((tret->type != 1) || (tret->code != 1))
    {
        tret--;
        if ((tret->type == 2) && (tret->code == 1))
        {
            tret--;
            ch1 = tret->val;
            tret++;
            tret++;
            ch2 = tret->val;
            ch1 = pow(ch1, ch2);
            sim.type = 0;
            sim.code = 0;
            sim.val = ch1;
            tret = test.erase(tret);;
            tret--;
            tret = test.erase(tret);
            tret--;
            tret = test.erase(tret);
            test.emplace(tret, sim);
            tret--;
        }
    }
    while ((tret->type != 1) || (tret->code != 2))
    {
        tret++;
        if (((tret->type == 2) && (tret->code == 2)) || ((tret->type == 2) && (tret->code == 3)))
        {
            if ((tret->type == 2) && (tret->code == 2))
            {
                tret--;
                ch1 = tret->val;
                tret++;
                tret++;
                ch2 = tret->val;
                ch1 = ch1 * ch2;
                sim.type = 0;
                sim.code = 0;
                sim.val = ch1;
                tret = test.erase(tret);
                tret--;
                tret = test.erase(tret);
                tret--;
                tret = test.erase(tret);
                test.emplace(tret, sim);
                tret--;

            }
            else
            {
                tret--;
                ch1 = tret->val;
                tret++;
                tret++;
                ch2 = tret->val;
                ch1 = ch1 / ch2;
                sim.type = 0;
                sim.code = 0;
                sim.val = ch1;
                tret = test.erase(tret);
                tret--;
                tret = test.erase(tret);
                tret--;
                tret = test.erase(tret);
                test.emplace(tret, sim);
                tret--;

            }
        }
    }
    while ((tret->type != 1) || (tret->code != 1))
    {
        tret--;
    }
    while ((tret->type != 1) || (tret->code != 2))
    {
        tret++;
        if (((tret->type == 2) && (tret->code == 4)) || ((tret->type == 2) && (tret->code == 5)))
        {
            if ((tret->type == 2) && (tret->code == 4))
            {
                tret--;
                ch1 = tret->val;
                tret++;
                tret++;
                ch2 = tret->val;
                ch1 = ch1 + ch2;
                sim.type = 0;
                sim.code = 0;
                sim.val = ch1;
                tret = test.erase(tret);
                tret--;
                tret = test.erase(tret);
                tret--;
                tret = test.erase(tret);
                test.emplace(tret, sim);
                tret--;

            }
            else
            {
                tret--;
                ch1 = tret->val;
                tret++;
                tret++;
                ch2 = tret->val;
                ch1 = ch1 - ch2;
                sim.type = 0;
                sim.code = 0;
                sim.val = ch1;
                tret = test.erase(tret);
                tret--;
                tret = test.erase(tret);
                tret--;
                tret = test.erase(tret);
                test.emplace(tret, sim);
                tret--;
            }
        }
    }
    cout << ch1 << endl;
}




void zamena(string &test, list<element_t> &vivod)
{
    int dl;
    int i;
    int flag;
    string ch;
    element_t sim;
    dl = test.size();
    auto iter = vivod.begin();
    for (i = 0; i < dl; i++ )
    {
        if (test[i] == '(')
        {
            sim.type = 1;
            sim.code = 1;
            sim.val = 0;
            vivod.push_back(sim);
        }
        if (test[i] == ')')
        {
            sim.type = 1;
            sim.code = 2;
            sim.val = 0;
            vivod.push_back(sim);
            flag = 0;
        }
        if (test[i] == '^')
        {
            sim.type = 2;
            sim.code = 1;
            sim.val = 0;
            vivod.push_back(sim);
            flag = 0;
        }
        if (test[i] == '*')
        {
            sim.type = 2;
            sim.code = 2;
            sim.val = 0;
            vivod.push_back(sim);
            flag = 0;
        }
        if (test[i] == '/')
        {
            sim.type = 2;
            sim.code = 3;
            sim.val = 0;
            vivod.push_back(sim);
            flag = 0;
        }
        if (test[i] == '+')
        {
            sim.type = 2;
            sim.code = 4;
            sim.val = 0;
            vivod.push_back(sim);
            flag = 0;
        }
        if (test[i] == '-')
        {
            if (test [i - 1] == '(')
            {
                ch = ch + '-';
                flag = 1;
            }
            else
            {
                sim.type = 2;
                sim.code = 5;
                sim.val = 0;
                vivod.push_back(sim);
                flag = 0;
            }

        }
        if (test [i] == '1')
        {
            ch = ch + '1';
            flag = 1;
        }
        if (test [i] == '2')
        {
            ch = ch + '2';
            flag = 1;
        }
        if (test [i] == '3')
        {
            ch = ch + '3';
            flag = 1;
        }
        if (test [i] == '4')
        {
            ch = ch + '4';
            flag = 1;
        }
        if (test [i] == '5')
        {
            ch = ch + '5';
            flag = 1;
        }
        if (test [i] == '6')
        {
            ch = ch + '6';
            flag = 1;
        }
        if (test [i] == '7')
        {
            ch = ch + '7';
            flag = 1;
        }
        if (test [i] == '8')
        {
            ch = ch + '8';
            flag = 1;
        }
        if (test [i] == '9')
        {
            ch = ch + '9';
            flag = 1;
        }
        if (test [i] == '0')
        {
            ch = ch + '0';
            flag = 1;
        }
        if (test [i] == ',')
        {
            ch = ch + '.';
            flag = 1;
        }
        if ((flag == 1) && ((test[i + 1] == '(') || (test[i+1] == ')') || (test[i+1] == '*') || (test[i+1] == '/') || (test[i+1] == '+') || (test[i+1] == '-') || (test[i+1] == '^')))
        {
            sim.type = 0;
            sim.code = 0;
            sim.val = stod(ch);
            vivod.push_back(sim);
            ch = "";
        }
    }
}


































int main()
{

    string primer;
    cin >> primer;
    primer = "(" + primer + ")";
    list<element_t> primerl;






    zamena(primer, primerl);
    udalenie(primerl);
    while(primerl.size() > 1)
    {
        skobki(primerl);
        udalenie(primerl);
    }


}