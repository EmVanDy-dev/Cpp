# # import hashlib

# # def text_to_sha256(text):
# #     # Encode the text to bytes
# #     text_bytes = text.encode('utf-8')
# #     print(text_bytes,'kk')
# #     # Create a SHA-256 hash object
# #     sha256 = hashlib.sha256()
    
# #     # Update the hash object with the byte data
# #     sha256.update(text_bytes)
    
# #     # Get the hexadecimal representation of the hash
# #     return sha256.hexdigest()

# # # Example usage
# # text = "hello world"
# # hash_value = text_to_sha256(text)
# # print("SHA-256 hash of '{}': {}".format(text, hash_value))
# # # Define a hash table mapping hashes to original texts
# # hash_table = {}

# # def add_to_hash_table(text):
# #     hash_value = text_to_sha256(text)
# #     hash_table[hash_value] = text

# # def get_text_from_hash(hash_value):
# #     return hash_table.get(hash_value, "Hash not found")

# # # Add the text to the hash table
# # text = "hello world"
# # add_to_hash_table(text)

# # # Retrieve the text using its hash
# # hash_value = text_to_sha256(text)
# # retrieved_text = get_text_from_hash(hash_value)
# # print("Original text retrieved from hash:", retrieved_text)
# class Hash:
#     def __init__(self, bucket_count):
#         self.bucket_count = bucket_count
#         self.table = [[] for _ in range(bucket_count)]

#     def hash_function(self, key):
#         return key % self.bucket_count

#     def insert_item(self, key):
#         index = self.hash_function(key)
#         if key not in self.table[index]:
#             self.table[index].append(key)

#     def delete_item(self, key):
#         index = self.hash_function(key)
#         if key in self.table[index]:
#             self.table[index].remove(key)

#     def display_hash(self):
#         for i, bucket in enumerate(self.table):
#             print(f"{i} --> {' --> '.join(map(str, bucket))}")
#             # print(bucket)
#         # for i in self.table.index:
#         #     print(i)


# class HashTable:
#     def __init__(self, table_size):
#         self.size = table_size
#         self.table = [[] for _ in range(table_size)]

#     def hash_function(self, key):
#         hash_value = 0
#         for ch in key:
#             hash_value = (hash_value * 31 + ord(ch)) % self.size
#         return hash_value

#     def insert(self, key):
#         index = self.hash_function(key)
#         if key not in self.table[index]:
#             self.table[index].append(key)

#     def delete_key(self, key):
#         index = self.hash_function(key)
#         if key in self.table[index]:
#             self.table[index].remove(key)
#         else:
#             print(f"Key not found: {key}")

#     def display(self):
#         for i, bucket in enumerate(self.table):
#             print(f"{i}: {' -> '.join(bucket)} -> nullptr")


# if __name__ == "__main__":
#     # Integer hash table
#     hash1 = Hash(10)
#     hash1.insert_item(20)
#     hash1.insert_item(11)
#     hash1.insert_item(12)
#     hash1.insert_item(23)
#     hash1.insert_item(5)
#     hash1.insert_item(17)
#     hash1.insert_item(8)
#     hash1.insert_item(9)
#     hash1.delete_item(12)
#     hash1.insert_item(13)
#     hash1.insert_item(57)
#     hash1.display_hash()

#     # String hash table
#     # hash_table = HashTable(10)
#     # hash_table.insert("apple")
#     # hash_table.insert("banana")
#     # hash_table.insert("grape")
#     # hash_table.insert("orange")
#     # hash_table.insert("pear")

#     # print("Hash Table:")
#     # hash_table.display()

#     # hash_table.delete_key("banana")
#     # print("Hash Table after deletion:")
#     # hash_table.display()

#     # hash_table.delete_key("kiwi")





import pandas as pd
import matplotlib.pyplot as plt

# Step 1: Create the DataFrame
data = {
    'UserName': ['vandy', 'dy', 'vandy', 'vandy'],
    'Email': ['5vandy@gamil.com', '1vandy@gamil.com', '2vandy@gamil.com', '4vandy@gamil.com'],
    'Password': ['123321', '123321', '123321', '123321']
}

# Custom index
index = ['a7b035', 'fc60b1', '18658a', '2cccce']

# Create the DataFrame
df = pd.DataFrame(data, index=index)

# Step 2: Prepare data for visualization
# Add a row with column names as part of the DataFrame
header = pd.DataFrame([df.columns.tolist()], columns=df.columns, index=['Column Names'])
# Combine header row with the original DataFrame
combined_df = pd.concat([header, df])

print("DataFrame with Column Names as Index:")
print(combined_df)

# Step 3: Plot the DataFrame as a table using matplotlib
fig, ax = plt.subplots(figsize=(12, 6))  # Adjust size as needed
ax.axis('off')  # Hide the axes

# Create the table
table = ax.table(cellText=combined_df.values,  # The data for the table
                 colLabels=combined_df.columns,  # Column headers
                 rowLabels=combined_df.index,  # Row labels
                 cellLoc='center',  # Center the text in cells
                 loc='center',  # Position of the table
                 colColours=['#f5f5f5']*combined_df.shape[1])  # Optional: background color for column headers

# Adjust layout for better appearance
table.auto_set_font_size(False)
table.set_fontsize(10)
table.auto_set_column_width(range(combined_df.shape[1]))  # Auto-set the width of columns

# Adjust the layout and display the plot
plt.title('User Data Table with Column Names as Index')
plt.show()








