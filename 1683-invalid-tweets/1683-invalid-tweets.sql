# Write your MySQL query statement below

# select tweet_id
# from Tweets 
# where  LENGTH("tweet_id") > 15;

select tweet_id
from Tweets
where LENGTH(content) > 15;