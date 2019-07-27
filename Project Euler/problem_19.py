#!/usr/bin/python3.6

# Start - Mon
WEEK_DAYS = list(range(1, 8))


def get_days(month, is_lp):
    thiry_days = [4, 6, 9, 11]

    if month in thiry_days:
        return 30

    if month == 2:
        return 29 if is_lp else 28

    return 31


calendars = []

for year in range(1901, 2001):
    leap_year = False

    if year % 4 == 0 or year % 400 == 0:
        leap_year = True

    year = {
        "year": year,
        "months": [],
        "days": 0
    }

    for month in range(1, 13):
        days = get_days(month, leap_year)
        year["days"] += days
        year["months"].append({
            "month": month,
            "days": days
        })

    calendars.append(year)

month_start = WEEK_DAYS[1]  # Tuesday 1 Jan 1901
sundays = 0

for year in calendars:
    # print(year["days"])
    for month in year["months"]:
        month_start_index = WEEK_DAYS.index(month_start) + (month["days"] % 7)
        month_start = WEEK_DAYS[
            month_start_index if month_start_index < 7 else (month_start_index % 7)
        ]

        if month_start == 7:
            sundays += 1

print(sundays)
