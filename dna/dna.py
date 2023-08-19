import csv
from sys import argv


def main():
    # Check for command-line usage
    if len(argv) != 3:
        print("Usage: python dna.py database.csv sequence.txt")
        return

    database_file = argv[1]
    sequence_file = argv[2]

    # Read database file into a variable
    database = []
    with open(database_file, newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            database.append(row)

    # Read DNA sequence file into a variable
    with open(sequence_file) as file:
        sequence = file.read().strip()

    # Find longest match of each STR in DNA sequence
    str_counts = {}
    for row in database:
        for str_name in row.keys():
            if str_name != 'name':
                str_count = longest_match(sequence, str_name)
                if str_name in str_counts:
                    str_counts[str_name] = max(str_counts[str_name], str_count)
                else:
                    str_counts[str_name] = str_count

    # Check database for matching profiles
    for row in database:
        match = True
        for str_name, str_count in str_counts.items():
            if str_name in row:
                if int(row[str_name]) != str_count:
                    match = False
                    break
        if match:
            print(row['name'])
            return

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in sequence, return longest run found
    return longest_run


if __name__ == '__main__':
    main()
