int problem1(string file_name){
    fstream s;
    s.open(file_name);

    string line;
    int sum = 0;

    while (getline(s, line)){

        stringstream issr;
        string ussr;
        for (int i = 0; i < line.length(); ++i) {
            if (line.at(i) == '[' || line.at(i) == ']' || line.at(i) == ',') {
                continue;
            }
            ussr.push_back(line.at(i));
        }
        issr = stringstream(ussr);
        int x = 0;
        while (issr >> x){
            sum+= x;
        }
    }
    cout << sum << endl;
    return sum;
}

void problem2(string file_name) {
    fstream s;
    s.open(file_name);

    string line;
    vector<int> nums(10, 0);

    int sum = 0;
    int doubleDigit = 0;


    while (getline(s, line)){

        stringstream issr;
        string ussr;
        for (int i = 0; i < line.length(); ++i) {
            if (line.at(i) == '[' || line.at(i) == ']' || line.at(i) == ',') {
                continue;
            }
            ussr.push_back(line.at(i));
        }
        issr = stringstream(ussr);
        int x = 0;
        while (issr >> x){
            switch(x){
                case '0':
                    nums[0]++;
                    break;
                case '1':
                    nums[1]++;
                    break;
                case '2':
                    nums[2]++;
                    break;
                case '3':
                    nums[3]++;
                    break;
                case '4':
                    nums[4]++;
                    break;
                case '5':
                    nums[5]++;
                    break;
                case '6':
                    nums[6]++;
                    break;
                case '7':
                    nums[7]++;
                    break;
                case '8':
                    nums[8]++;
                    break;
                case '9':
                    nums[9]++;
                    break;
                default:
                    doubleDigit ++;
            }


        }
    }
    for (int i = 0; i < nums.size(); ++i){
        cout << "Count of nums " << i << ":" << nums[0] << endl;

    }

}

void problem3(string file_name) {
    fstream s;
    s.open(file_name);

    string line;
    int count = 0;
    int max_count = 0;
    vector<int> numbers;

    while (getline(s, line)) {

        stringstream issr;
        string ussr;
        for (int i = 0; i < line.length(); ++i) {
            if (line.at(i) == '[' || line.at(i) == ']' || line.at(i) == ',') {
                continue;
            }
            ussr.push_back(line.at(i));
        }
        issr = stringstream(ussr);
        int x = 0;
        while (issr >> x) {
            numbers.push_back(x);
        }
        sort(numbers.begin(), numbers.end());

        int ccount = 0;
        int res = numbers[0];

        for (int i = 1; i < numbers.size(); i++) {
            if (numbers[i] == numbers[i - 1])
                ccount++;
            else {
                if (ccount > max_count) {
                    max_count = ccount;
                    res = numbers[i - 1];
                }
                ccount = 1;
            }
        }

        if (ccount > max_count)
        {
            max_count = ccount;
            res = numbers[numbers.size() - 1];
        }

        cout << res;
        break;


    }
}



int main() {
    string s = "C:\\Users\\Predecessor\\Desktop\\Stuff\\School\\MCS 360\\data.txt";
    problem1(s);
    problem2(s);
    problem3(s);

	return 0;
}

