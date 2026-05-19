CREATE TABLE IF NOT EXISTS forum_categories (
    id INT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    slug VARCHAR(120) NOT NULL,
    description TEXT NULL,
    sort_order INT NOT NULL DEFAULT 0,
    is_locked TINYINT(1) NOT NULL DEFAULT 0,
    created_at INT UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

CREATE TABLE IF NOT EXISTS forum_topics (
    id INT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    category_id INT UNSIGNED NOT NULL,
    account_id INT UNSIGNED NOT NULL,
    title VARCHAR(180) NOT NULL,
    slug VARCHAR(200) NOT NULL,
    is_sticky TINYINT(1) NOT NULL DEFAULT 0,
    is_locked TINYINT(1) NOT NULL DEFAULT 0,
    views INT UNSIGNED NOT NULL DEFAULT 0,
    created_at INT UNSIGNED NOT NULL,
    updated_at INT UNSIGNED NOT NULL,
    last_post_at INT UNSIGNED NOT NULL,
    last_post_account_id INT UNSIGNED NULL,
    INDEX(category_id),
    INDEX(last_post_at),
    INDEX(is_sticky)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

CREATE TABLE IF NOT EXISTS forum_posts (
    id INT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    topic_id INT UNSIGNED NOT NULL,
    account_id INT UNSIGNED NOT NULL,
    content MEDIUMTEXT NOT NULL,
    created_at INT UNSIGNED NOT NULL,
    updated_at INT UNSIGNED NULL,
    is_deleted TINYINT(1) NOT NULL DEFAULT 0,
    INDEX(topic_id),
    INDEX(account_id)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

INSERT INTO forum_categories (name, slug, description, sort_order, is_locked, created_at)
VALUES
('Announcements', 'announcements', 'Official Frostforge updates, development posts and important server announcements.', 1, 1, UNIX_TIMESTAMP()),
('Campaign Feedback', 'campaign-feedback', 'Share feedback about the Frostforge campaign, dungeon chapters, lore bridges and progression flow.', 2, 0, UNIX_TIMESTAMP()),
('Bug Reports', 'bug-reports', 'Report quest, dungeon, website, account or gameplay issues.', 3, 0, UNIX_TIMESTAMP()),
('Playerbots & Help', 'playerbots-help', 'Ask questions about Playerbots, group setup, dungeon control and useful commands.', 4, 0, UNIX_TIMESTAMP()),
('Suggestions', 'suggestions', 'Suggest improvements for Frostforge systems, campaign flow, website or community features.', 5, 0, UNIX_TIMESTAMP()),
('General Discussion', 'general-discussion', 'General Frostforge discussion, introductions and community talk.', 6, 0, UNIX_TIMESTAMP());
