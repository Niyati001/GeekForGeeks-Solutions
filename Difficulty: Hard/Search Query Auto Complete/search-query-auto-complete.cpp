class AutoCompleteSystem {
    unordered_map<string, int> freq;
    string prefix;

public:
    AutoCompleteSystem(vector<string>& sentences, vector<int>& times) {
        for (int i = 0; i < sentences.size(); i++) {
            freq[sentences[i]] += times[i];
        }
        prefix = "";
    }

    vector<string> input(char c) {
        if (c == '#') {
            freq[prefix]++;
            prefix = "";
            return {};
        }

        prefix += c;

        vector<string> candidates;

        // Find all sentences matching the current prefix
        for (auto& [sentence, count] : freq) {
            if (sentence.size() >= prefix.size() &&
                sentence.compare(0, prefix.size(), prefix) == 0) {
                candidates.push_back(sentence);
            }
        }

        // Higher frequency first; ASCII lexicographical order on ties
        sort(candidates.begin(), candidates.end(),
             [&](const string& a, const string& b) {
                 if (freq[a] != freq[b])
                     return freq[a] > freq[b];
                 return a < b;
             });

        if (candidates.size() > 3)
            candidates.resize(3);

        return candidates;
    }
};


/**
 * Your AutoCompleteSystem object will be instantiated and called as follows:
 *
 * AutoCompleteSystem* obj =
 *     new AutoCompleteSystem(sentences, times);
 *
 * vector<string> suggestions = obj->input(c);
 */