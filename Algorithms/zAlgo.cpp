vector<int> computeZArray(const string & s) {
    int n = s.length();
    vector<int> Z(n);
    int L = 0, R = 0, K;
    for (int i = 1; i < n; ++i) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R] == s[R - L]) {
                R++;
            }
            Z[i] = R - L;
            R--;
        } else {
            K = i - L;
            if (Z[K] < R - i + 1) {
                Z[i] = Z[K];
            } else {
                L = i;
                while (R < n && s[R] == s[R - L]) {
                    R++;
                }
                Z[i] = R - L;
                R--;
            }
        }
    }
    return Z;
}
vector<int> searchPattern(const string & text, const string & pattern) {
    string concat = pattern + "$" + text;
    vector<int> Z = computeZArray(concat);
    vector<int> result;
    for (int i = 0; i < Z.size(); ++i) {
        if (Z[i] == pattern.length()) {
            result.push_back(i - pattern.length() - 1);
        }
    }
    return result;
}