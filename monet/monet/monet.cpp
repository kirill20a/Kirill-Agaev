#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class CoinSolver {
private:
    int totalCoins;
    vector<int> coins; // 0 - unknown, 1 - real, -1 - light fake, 2 - heavy fake
    vector<vector<int>> weighHistory;

public:
    CoinSolver(int n) : totalCoins(n), coins(n + 1, 0) {} // coins numbered from 1 to n

    // Check if problem is solved
    bool isSolved() {
        int fakeCount = 0;
        for (int i = 1; i <= totalCoins; i++) {
            if (coins[i] == -1 || coins[i] == 2) {
                fakeCount++;
            }
        }
        return fakeCount == 1;
    }

    // Get coins with unknown status
    vector<int> getUnknownCoins() {
        vector<int> unknown;
        for (int i = 1; i <= totalCoins; i++) {
            if (coins[i] == 0) unknown.push_back(i);
        }
        return unknown;
    }

    // Get real coins
    vector<int> getRealCoins() {
        vector<int> real;
        for (int i = 1; i <= totalCoins; i++) {
            if (coins[i] == 1) real.push_back(i);
        }
        return real;
    }

    // Get candidate fake coins (light or heavy)
    vector<int> getCandidateFakes() {
        vector<int> candidates;
        for (int i = 1; i <= totalCoins; i++) {
            if (coins[i] == -1 || coins[i] == 2) {
                candidates.push_back(i);
            }
        }
        return candidates;
    }

    // Perform weighing
    void performWeighing(const vector<int>& left, const vector<int>& right) {
        cout << "Weighing " << weighHistory.size() + 1 << ":\n";
        cout << "Left pan: ";
        for (int coin : left) cout << coin << " ";
        cout << "\nRight pan: ";
        for (int coin : right) cout << coin << " ";
        cout << "\n";

        cout << "Result (1 - left heavier, 2 - right heavier, 3 - equal): ";
        int result;
        cin >> result;

        weighHistory.push_back({ result });

        // Analyze result
        if (result == 3) { // Balance
            // All coins on scales are real
            for (int coin : left) coins[coin] = 1;
            for (int coin : right) coins[coin] = 1;
        }
        else if (result == 1) { // Left heavier
            updateStatus(left, right);
        }
        else { // Right heavier
            updateStatus(right, left);
        }

        // Make logical deductions
        checkDeductions();
    }

    // Update coin statuses after unbalanced weighing
    void updateStatus(const vector<int>& heavySide, const vector<int>& lightSide) {
        // Mark coins not on scales as unknown (no change)

        // Coins on heavy side cannot be light
        for (int coin : heavySide) {
            if (coins[coin] == 0) coins[coin] = 2; // candidate heavy
            else if (coins[coin] == -1) coins[coin] = 1; // was light candidate, now real
        }

        // Coins on light side cannot be heavy
        for (int coin : lightSide) {
            if (coins[coin] == 0) coins[coin] = -1; // candidate light
            else if (coins[coin] == 2) coins[coin] = 1; // was heavy candidate, now real
        }

        // Coins not on scales remain unknown
        vector<bool> onScale(totalCoins + 1, false);
        for (int coin : heavySide) onScale[coin] = true;
        for (int coin : lightSide) onScale[coin] = true;

        for (int i = 1; i <= totalCoins; i++) {
            if (!onScale[i] && coins[i] == 0) {
                // Keep as unknown
            }
        }
    }

    // Check logical deductions
    void checkDeductions() {
        bool changed;
        do {
            changed = false;
            vector<int> realCoins = getRealCoins();

            // If we have real coins, use them to eliminate candidates
            if (!realCoins.empty()) {
                int realCoin = realCoins[0];
                vector<int> candidates = getCandidateFakes();

                // If only one candidate remains, others must be real
                if (candidates.size() == 1) {
                    for (int i = 1; i <= totalCoins; i++) {
                        if (i != candidates[0] && coins[i] != 1) {
                            coins[i] = 1;
                            changed = true;
                        }
                    }
                }
            }

        } while (changed);
    }

    // Strategy for next weighing
    void nextWeighing() {
        if (isSolved()) {
            printSolution();
            return;
        }

        vector<int> unknown = getUnknownCoins();
        vector<int> realCoins = getRealCoins();
        vector<int> candidates = getCandidateFakes();

        // If we have candidate fakes, test them against real coins
        if (!candidates.empty() && !realCoins.empty()) {
            int realCoin = realCoins[0];
            vector<int> left, right;

            // Test candidates against real coins
            for (int i = 0; i < min(2, (int)candidates.size()); i++) {
                if (i % 2 == 0) left.push_back(candidates[i]);
                else right.push_back(candidates[i]);
            }

            // Balance with real coins
            while (left.size() < right.size()) left.push_back(realCoin);
            while (right.size() < left.size()) right.push_back(realCoin);

            performWeighing(left, right);
        }
        // If we have real coins but no specific candidates
        else if (!realCoins.empty()) {
            int realCoin = realCoins[0];
            vector<int> left, right;

            // Test unknown coins
            int numToTest = min(3, (int)unknown.size());
            for (int i = 0; i < numToTest; i++) {
                if (i % 2 == 0) left.push_back(unknown[i]);
                else right.push_back(unknown[i]);
            }

            // Balance with real coins
            while (left.size() < right.size()) left.push_back(realCoin);
            while (right.size() < left.size()) right.push_back(realCoin);

            performWeighing(left, right);
        }
        else {
            // First weighing - divide into three groups
            int groupSize = totalCoins / 3;
            vector<int> left, right;

            for (int i = 1; i <= groupSize; i++) left.push_back(i);
            for (int i = groupSize + 1; i <= 2 * groupSize; i++) right.push_back(i);

            performWeighing(left, right);
        }
    }

    // Print solution
    void printSolution() {
        cout << "\n=== SOLUTION FOUND ===\n";
        for (int i = 1; i <= totalCoins; i++) {
            if (coins[i] == -1) {
                cout << "Coin " << i << " - FAKE (LIGHTER)\n";
            }
            else if (coins[i] == 2) {
                cout << "Coin " << i << " - FAKE (HEAVIER)\n";
            }
            else {
                cout << "Coin " << i << " - real\n";
            }
        }
        cout << "Total weighings: " << weighHistory.size() << "\n";
    }

    // Solve the problem
    void solve() {
        cout << "Finding fake coin among " << totalCoins << " coins\n";
        cout << "Fake coin may be lighter or heavier than real coins\n\n";

        int maxWeighings = ceil(log(totalCoins * 2) / log(3)) + 1;

        while (!isSolved() && weighHistory.size() < maxWeighings) {
            nextWeighing();
        }

        if (!isSolved()) {
            cout << "Could not find solution in " << maxWeighings << " weighings\n";
            cout << "Current status:\n";
            for (int i = 1; i <= totalCoins; i++) {
                if (coins[i] == -1) cout << "Coin " << i << " - possibly light fake\n";
                else if (coins[i] == 2) cout << "Coin " << i << " - possibly heavy fake\n";
                else if (coins[i] == 1) cout << "Coin " << i << " - real\n";
                else cout << "Coin " << i << " - unknown\n";
            }
        }
    }
};

int main() {
    int n;
    cout << "Enter number of coins: ";
    cin >> n;

    if (n < 3) {
        cout << "Too few coins for solution\n";
        return 1;
    }

    CoinSolver solver(n);
    solver.solve();

    return 0;
}