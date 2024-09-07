class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int offset = k % n;

        // Crear una copia de nums con el mismo tamaño
        vector<int> copy(n);

        // Copiar los elementos a 'copy'
        for (int i = 0; i < n; i++) {
            copy[i] = nums[i];
        }

        // Rotar los elementos
        for (int i = 0; i < n; i++) {
            nums[(i + offset) % n] = copy[i];
        }
    }
};