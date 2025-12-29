class Solution {
public:
    // Memoization: stores whether a given level can build a valid pyramid
    unordered_map<string, bool> memo;

    // Generate all possible upper-level strings from the current level
    void generateNextLevels(
        int index,
        string &currentLevel,
        unordered_map<string, unordered_set<char>> &allowedMap,
        vector<string> &nextLevels,
        string currentUpper
    ) {
        if (index == currentLevel.size()) {
            nextLevels.push_back(currentUpper);
            return;
        }

        string basePair = currentLevel.substr(index - 1, 2);

        for (char topChar : allowedMap[basePair]) {
            generateNextLevels(
                index + 1,
                currentLevel,
                allowedMap,
                nextLevels,
                currentUpper + topChar
            );
        }
    }

    // Wrapper to get all possible upper layers
    vector<string> buildUpperLevels(
        string &currentLevel,
        unordered_map<string, unordered_set<char>> &allowedMap
    ) {
        vector<string> nextLevels;
        generateNextLevels(1, currentLevel, allowedMap, nextLevels, "");
        return nextLevels;
    }

    // Recursive function to check if pyramid can be built
    bool canBuildPyramid(
        string &currentLevel,
        unordered_map<string, unordered_set<char>> &allowedMap
    ) {
        if (currentLevel.size() == 1)
            return true;

        if (memo.count(currentLevel))
            return memo[currentLevel];

        vector<string> upperLevels = buildUpperLevels(currentLevel, allowedMap);

        for (string &upper : upperLevels) {
            if (canBuildPyramid(upper, allowedMap))
                return memo[currentLevel] = true;
        }

        return memo[currentLevel] = false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, unordered_set<char>> allowedMap;

        // Build mapping: "AB" -> {C, D}
        for (string &rule : allowed) {
            allowedMap[rule.substr(0, 2)].insert(rule[2]);
        }

        return canBuildPyramid(bottom, allowedMap);
    }
};