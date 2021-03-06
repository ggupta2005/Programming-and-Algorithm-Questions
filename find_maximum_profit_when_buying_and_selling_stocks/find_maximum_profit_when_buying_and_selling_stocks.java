/*
 * Say you have an array for which the ith element is the price of a given
 * stock on day i. If you were only permitted to complete at most one
 * transaction (ie, buy one and sell one share of the stock), design an
 * algorithm to find the maximum profit.
 *
 * Example 1:
 * Input: [7, 1, 5, 3, 6, 4]
 * Output: 5
 * max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to
 *                            be larger than buying price)
 * Example 2:
 * Input: [7, 6, 4, 3, 1]
 * Output: 0
 * In this case, no transaction is done, i.e. max profit = 0.
 */
import java.io.*;
import java.util.*;

public class find_maximum_profit_when_buying_and_selling_stocks
{
    /*
     * This function takes an array of stock prices for different days and
     * returns the maximum possible profit given that one can buy on one day
     * and sell at another day. The time complexity of this function is
     * O(n^2) where 'n' is the number of days in the array and the space
     * complexity of this function is O(1).
     */
    public static int find_max_profit_when_buying_and_selling_stocks_v1
                                                            (int[] prices)
    {
        int max, len;
        int i, j;

        /*
         * If the prices array is invalid or the number of elements in
         * the array is less than or equal to one, then return zero
         */
        if ((prices == null) || (prices.length <= 1)) {
            return(0);
        }

        /*
         * Set maximum profit to zero
         */
        max = 0;

        len = prices.length;

        /*
         * Iterate over all combinations of the days
         */
        for (i = 0; i < (len - 1); ++i) {
            for (j = i + 1; j < len; ++j) {

                /*
                 * If the price on the jth day is greater
                 * han the price on the ith day, then update
                 * the maximum possible profit
                 */
                if (prices[j] > prices[i]) {

                    /*
                     * If the maximum profit is lesser than the
                     * difference of the price on the jth day
                     * and the price on the ith day, then update
                     * the maximum profit
                     */
                    if (max < (prices[j] - prices[i])) {
                        max = prices[j] - prices[i];
                    }
                }
            }
        }

        /*
         * Return the maximum profit
         */
        return(max);
    }

    /*
     * This function takes an array of stock prices for different days and
     * returns the maximum possible profit given that one can buy on one day
     * and sell at another day. The time complexity of this function is
     * O(n) where 'n' is the number of days in the array. The space complexity
     * of this function is O('n').
     */
    public static int find_max_profit_when_buying_and_selling_stocks_v2
                                                            (int[] prices)
    {
        int max, len;
        int[] max_future_prices;
        int i, j;

        /*
         * If the prices array is invalid or the number of elements in
         * the array is less than or equal to one, then return zero
         */
        if ((prices == null) || (prices.length <= 1)) {
            return(0);
        }

        /*
         * Allocate a temporary array for storing maximum prices
         * seen in future from a given day
         */
        max_future_prices = new int[prices.length];

        /*
         * If the array allocation fails, then return zero
         */
        if (max_future_prices == null) {
            return(0);
        }

        len = prices.length;

        /*
         * Populate the maximum prices array. Set the last element in
         * the array to be the last element of the prices array
         */
        max_future_prices[len - 1] = prices[len - 1];
        for (i = len - 2; i >= 0; --i) {

            if (max_future_prices[i + 1] > prices[i]) {

                /*
                 * If the maximum price on the next of the ith day is
                 * greater than the price on the current day, then set
                 * the maximum price on the current day to be equal to
                 * maximum price of the next day.
                 */
                max_future_prices[i] = max_future_prices[i + 1];
            } else {

                /*
                 * Otherwise set the maximum price on the ith day
                 * to be the price seen on the current day
                 */
                max_future_prices[i] = prices[i];
            }
        }

        /*
         * Set maximum profit to zero
         */
        max = 0;

        for (i = 0; i < len; ++i) {

            /*
             * For each day, if the difference between the maximum
             * price seen on the day is greater than the price seen
             * on that day, then update the maximum profit.
             */
            if ((max_future_prices[i] - prices[i]) > 0) {
                if (max < (max_future_prices[i] - prices[i])) {
                    max = max_future_prices[i] - prices[i];
                }
            }
        }

        /*
         * Return the maximum profit
         */
        return(max);
    }

    public static void main (String[] args)
    {
        /*
         * Test 0: Test when prices array is null. The maximum profit
         *         should be zero.
         */
        int[] prices0 = null;
        assert(
            0 == find_max_profit_when_buying_and_selling_stocks_v1(prices0));
        assert(
            0 == find_max_profit_when_buying_and_selling_stocks_v2(prices0));

        /*
         * Test 1: Test when prices array has one element. The maximum
         *         profit should be zero.
         */
        int prices1[] = {1};
        assert(
            0 == find_max_profit_when_buying_and_selling_stocks_v1(prices1));
        assert(
            0 == find_max_profit_when_buying_and_selling_stocks_v2(prices1));

        /*
         * Test 2: Test when prices array has two elements but in
         *         decreasing order. The maximum profit should be zero.
         */
        int prices2[] = {2, 1};
        assert(
            0 == find_max_profit_when_buying_and_selling_stocks_v1(prices2));
        assert(
            0 == find_max_profit_when_buying_and_selling_stocks_v2(prices2));

        /*
         * Test 3: Test when prices array has two elements and in
         *         increasing order. The maximum profit should be
         *         difference between the second price element and the
         *         first price element.
         */
        int prices3[] = {1, 2};
        assert(
            prices3[1] - prices3[0]
                == find_max_profit_when_buying_and_selling_stocks_v1(prices3));
        assert(
            prices3[1] - prices3[0]
                == find_max_profit_when_buying_and_selling_stocks_v2(prices3));

        /*
         * Test 4: Test a case where the prices array has many elements but
         *         not in any specific order. The maximum profit should be
         *         non-zero.
         */
        int prices4[] = {7, 1, 5, 3, 6, 4};
        assert(
            5 == find_max_profit_when_buying_and_selling_stocks_v1(prices4));
        assert(
            5 == find_max_profit_when_buying_and_selling_stocks_v2(prices4));

        /*
         * Test 5: Test a case where the prices array has many elements but
         *         in decreasing order. The maximum profit should be zero.
         */
        int prices5[] = {7, 6, 4, 3, 1};
        assert(
            0 == find_max_profit_when_buying_and_selling_stocks_v1(prices5));
        assert(
            0 == find_max_profit_when_buying_and_selling_stocks_v2(prices5));

        /*
         * Test 6: Test a case where the prices array has many elements but
         *         in increasing order. The maximum profit should be
         *         difference between maximum and minimum element.
         */
        int prices6[] = {1, 3, 4, 6, 7};
        assert(
            prices6[prices6.length - 1] - prices6[0]
                == find_max_profit_when_buying_and_selling_stocks_v1(prices6));
        assert(
            prices6[prices6.length - 1] - prices6[0]
                == find_max_profit_when_buying_and_selling_stocks_v2(prices6));

        /*
         * Test 7: Test a case where the prices array has many elements but
         *         all are equal. The maximum profit should be zero.
         */
        int prices7[] = {7,7,7,7,7,7,7,7,7,7,7};
        assert(
            0 == find_max_profit_when_buying_and_selling_stocks_v1(prices7));
        assert(
            0 == find_max_profit_when_buying_and_selling_stocks_v2(prices7));
    }
}
