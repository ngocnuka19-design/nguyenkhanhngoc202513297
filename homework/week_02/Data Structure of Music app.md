
## 1. Stable Data Structures

### User Object
The `user_database` is a Hash Map where the **Key** is the `User_id` (int) and the **Value** is the `User` .
(object).

| Field Name    | Data Type      |
| :------------ | :------------- |
| **`User_id`** | **`int`**      |
| `Username`    | `varchar(100)` |
| `email`       | `varchar(255)` |
| `password`    | `varchar(255)` |
| `region_id`   | `int`          |

### Track Object
The `track_database` is a Hash Map where the **Key** is the `Track_id` (int) and the **Value** is the `Track` (object).

| Field Name     | Data Type      |
| :------------- | :------------- |
| **`Track_id`** | **`int`**      |
| `Title`        | `varchar(255)` |
| `Album`        | `varchar(255)` |
| `Genre`        | `varchar(100)` |

---

## 2. Dynamic Data Structures (Interactions)

These Nested Hash Maps and Hash Sets track the relationships between users and tracks to power the recommendation engines.

*   **`User_listen_history`**: Links `User_id` (int) to an inner `listen_history` Hash Map.
    *   *Inner `listen_history`*: Links `Track_id` (int) with their `listen_counts` (int).
*   **`Track_listeners`**: Links `Track_id` (int) to an inner `history_listen` Hash Map.
    *   *Inner `history_listen`: Links `User_id` (int) with their `listen_counts` (int).
*   **`User_likes`**: Link `User_id` (int) to `Track_id` (int) to maintain a user's liked list.
*   **`Track_likers`**: Link `Track_id` (int) to `User_id` (int) to maintain a list of who likes a specific track.
*   **`Track_countlikes`**: A Hash Map linking `Track_id` (int) with `Total_likes` (int) (**derived** from the `Track_likers` and is used for generating leaderboards).

---

## 3. Algorithms

### Creating a Chart of n Tracks
*   Sort the `Track_countlikes` data structure to instantly generate a leaderboard of the most popular tracks.

### Searching for Similar Users & Recommending Music
1.  **Candidate Generation**: Using the track you listen to the most, search for other people who also have that track high on their `listen_history` or who have liked that track => A list of: **Candidate Users**
2.  **Scoring & Overlap**: Search within that list of candidate users to find the specific user who has the highest track overlap (could use both `Track_likers` or `User_listen_history`) with you.
3.  **Recommendation**: Recommend the unique tracks from that similar user's history directly to you.


---

## 4. Credits
- For database: https://databasesample.com/database/spotify-database
- For algorithms: Đỗ Đức Hoàng and Gemini
- For writing: Obisidian