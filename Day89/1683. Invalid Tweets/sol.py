import pandas as pd

def invalid_tweets(df: pd.DataFrame) -> pd.DataFrame:
    data = df[df.content.str.len() > 15]

    return data[['tweet_id']]
