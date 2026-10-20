

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        
        // n के सभी संभावित भाजक (Divisors) 'k' की जाँच करें
        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue; // k का n को विभाजित करना अनिवार्य है
            
            bool valid_k = true;
            int prev_max = -1e9; // पिछले ब्लॉक के अधिकतम मान को ट्रैक करने के लिए
            
            // एरे को k साइज़ के ब्लॉक्स में विभाजित करें
            for (int i = 0; i < n; i += k) {
                int current_min = nums[i];
                int current_max = nums[i];
                int drops = 0;
                
                // वर्तमान ब्लॉक की जाँच करें
                for (int j = i; j < i + k; ++j) {
                    current_min = min(current_min, nums[j]);
                    current_max = max(current_max, nums[j]);
                    
                    // ब्लॉक के अंदर का ड्रॉप देखें
                    if (j > i && nums[j] < nums[j - 1]) {
                        drops++;
                    }
                }
                
                // साइक्लिकली रोटेटेड होने के लिए अंतिम और पहले तत्व के बीच का ड्रॉप
                if (k > 1 && nums[i + k - 1] > nums[i]) {
                    drops++;
                }
                
                // शर्त 1: ब्लॉक में 1 से अधिक ड्रॉप नहीं होना चाहिए (यदि k=1 है तो 0 ड्रॉप)
                // शर्त 2: यदि ब्लॉक में एक ड्रॉप है, तो आखिरी एलिमेंट पहले से बड़ा नहीं हो सकता (ताकि वो साइकिल हो सके)
                if (drops > 1) {
                    valid_k = false;
                    break;
                }
                
                // विशेष मामला: जब एक ही ड्रॉप हो, तो वो उचित सर्कुलर रोटेशन होना चाहिए
                if (drops == 1) {
                    // एक रोटेटेड सॉर्टेड एरे में मिनिमम एलिमेंट ढूंढें जो ड्रॉप के तुरंत बाद होता है
                    int min_idx = i;
                    for (int j = i + 1; j < i + k; ++j) {
                        if (nums[j] < nums[j - 1]) {
                            min_idx = j;
                            break;
                        }
                    }
                    // सत्यापित करें कि रोटेशन के बाद यह पूरी तरह सॉर्टेड है
                    int real_min = nums[min_idx];
                    int real_max = nums[min_idx == i ? i + k - 1 : min_idx - 1];
                    
                    if (real_min < prev_max) {
                        valid_k = false;
                        break;
                    }
                } else {
                    // यदि 0 ड्रॉप्स हैं (यानी ब्लॉक पहले से ही सॉर्टेड है)
                    if (current_min < prev_max) {
                        valid_k = false;
                        break;
                    }
                }
                
                prev_max = current_max;
            }
            
            if (valid_k) {
                total_sum += k;
            }
        }
        
        return total_sum;
    }
};
