#include <bits/stdc++.h>
#include <string>

using namespace std;

struct Encoding
{
    char data;
    unsigned freq;

    Encoding *left, *right;

    Encoding(char data, unsigned freq)
    {
        this->data = data, this->freq = freq;
        left = right = nullptr;
    }
};
struct compare
{
    bool operator()(Encoding *l, Encoding *r)
    {
        return l->freq > r->freq;
    }
};
Encoding *HuffmanEncoding(string input)
{
    map<char, int> freqMap;
    for (char ch : input)
        freqMap[ch]++;

    priority_queue<Encoding *, vector<Encoding *>, compare> minHeap;

    Encoding *left, *right, *top;

    for (auto pair : freqMap)
        minHeap.push(new Encoding(pair.first, pair.second));

    while (minHeap.size() > 1)
    {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new Encoding('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    return minHeap.top();
}
void PrintCodes(Encoding *root, string str)
{
    if (!root)
        return;

    if (root->data != '$')
    {
        cout << root->data << " : " << str << endl;
    }
    PrintCodes(root->left, str + "0");
    PrintCodes(root->right, str + "1");
}
string Decode(Encoding *root, string &code)
{
    Encoding *temp = root;
    string decodedStr = "";
    for (int i = 0; i < code.length(); i++)
    {
        if (!temp->left || !temp->right)
        {
            decodedStr += temp->data;
            temp = root;
        }
        else if (code[i] == '0')
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return decodedStr;
}
int main()
{
    string input;
    cout << "Enter the input string to encode : ";
    cin >> input;
    Encoding *encTree = HuffmanEncoding(input);
    PrintCodes(encTree, "");
    return 0;
}