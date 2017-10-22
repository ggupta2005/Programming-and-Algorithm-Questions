/*
 * Design a logger system that receive stream of messages along with its
 * timestamps, each message should be printed if and only if it is not
 * printed in the last 10 seconds.
 *
 * Given a message and a timestamp (in seconds granularity), return true
 * if the message should be printed in the given timestamp, otherwise returns
 * false.
 *
 * It is possible that several messages arrive roughly at the same time.
 *
 * Example:
 *
 * Logger logger = new Logger();
 *
 * // logging string "foo" at timestamp 1
 * logger.shouldPrintMessage(1, "foo"); returns true;
 *
 * // logging string "bar" at timestamp 2
 * logger.shouldPrintMessage(2,"bar"); returns true;
 *
 * // logging string "foo" at timestamp 3
 * logger.shouldPrintMessage(3,"foo"); returns false;
 *
 * // logging string "bar" at timestamp 8
 * logger.shouldPrintMessage(8,"bar"); returns false;
 *
 * // logging string "foo" at timestamp 10
 * logger.shouldPrintMessage(10,"foo"); returns false;
 *
 * // logging string "foo" at timestamp 11
 * logger.shouldPrintMessage(11,"foo"); returns true;
 */
import java.io.*;
import java.util.*;

public class logger_rate_limiter {

    Hashtable<String, Integer> ht;

    /** Initialize your data structure here. */
    public logger_rate_limiter()
    {
        ht = new Hashtable<String, Integer>();
    }

    /** Returns true if the message should be printed in the given timestamp,
        otherwise returns false. If this method returns false, the message
        will not be printed. The timestamp is in seconds granularity. */
    public boolean shouldPrintMessage(int timestamp, String message)
    {
        /*
         * If the log message doesn't exist in the hash table, then add
         * the log message in the hash table and return 'true'.
         */
        if (ht.get(message) == null) {
            ht.put(message, new Integer(timestamp));
            return(true);
        }

        /*
         * Get the previous timestamp of the log message from the hash table
         */
        int previous_timestamp = ((Integer)ht.get(message)).intValue();

        /*
         * If the different between the previous timestamp and the new
         * timestamp is greater than or equal to ten, then update the
         * timestamp of the log message in the hash table and return 'true'
         */
        if ((timestamp - previous_timestamp) >= 10) {
            ht.put(message, new Integer(timestamp));
            return(true);
        }

        /*
         * In all other cases, return 'false'
         */
        return(false);
    }

    public static void main (String[] args)
    {
        logger_rate_limiter logger = new logger_rate_limiter();

        // logging string "foo" at timestamp 1
        assert(logger.shouldPrintMessage(1, "foo"));

        // logging string "bar" at timestamp 2
        assert(logger.shouldPrintMessage(2,"bar"));

        // logging string "foo" at timestamp 3
        assert(!logger.shouldPrintMessage(3,"foo"));

        // logging string "bar" at timestamp 8
        assert(!logger.shouldPrintMessage(8,"bar"));

        // logging string "foo" at timestamp 10
        assert(!logger.shouldPrintMessage(10,"foo"));

        // logging string "foo" at timestamp 11
        assert(logger.shouldPrintMessage(11,"foo"));
    }
}
