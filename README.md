curl 'https://leetcode.com/graphql' \
  -H 'authority: leetcode.com' \
  -H 'accept: */*' \
  -H 'accept-language: zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6' \
  -H 'content-type: application/json' \
  -H 'cookie: __cf_bm=BxAPF0JgFV.thcXZsW01lMbud6QxBiwRcX6dh1Y5PhU-1720624015-1.0.1.1-XpSeyb_kjVP7MG2VnQBSYjmr0kowMduLaSi5L3s41dyZVmaMFYJMamvJWosuDSCVOOPARlFNqF14BIMdFXMvLg; _gid=GA1.2.2119322361.1720624026; ip_check=(false, "103.94.185.248"); gr_user_id=26ec56a7-5d07-4e31-a64f-5eb009427196; 87b5a3c3f1a55520_gr_session_id=5b3ed5a7-804e-4efe-a81b-de0fe1aede2f; 87b5a3c3f1a55520_gr_session_id_sent_vst=5b3ed5a7-804e-4efe-a81b-de0fe1aede2f; _gat=1; csrftoken=NeXKqwOF2hcvZiK0mejasObr62UH5xcX0wPy9Vv9Dq3bwhdHsR52S4PzMYBEhu5M; messages=W1siX19qc29uX21lc3NhZ2UiLDAsMjUsIlN1Y2Nlc3NmdWxseSBzaWduZWQgaW4gYXMgbW9ub3BvZGl1bS4iXV0:1sRZ8J:cPVq2ryeYIidK2HkFss9usRJSAvgw9YGw58tTOVyGTs; LEETCODE_SESSION=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJfYXV0aF91c2VyX2lkIjoiMTA3NjQzMzEiLCJfYXV0aF91c2VyX2JhY2tlbmQiOiJkamFuZ28uY29udHJpYi5hdXRoLmJhY2tlbmRzLk1vZGVsQmFja2VuZCIsIl9hdXRoX3VzZXJfaGFzaCI6IjYwOGE1ZjE4NDQ0ZTc5MTVkMGNlNDAyNGQyZDcwNTdmOGYwNWY5OWE3MTQyMmZjMDgzNDljYTYwNjU5NGI4MDciLCJpZCI6MTA3NjQzMzEsImVtYWlsIjoiOTQ2NzMxODA5QHFxLmNvbSIsInVzZXJuYW1lIjoibW9ub3BvZGl1bSIsInVzZXJfc2x1ZyI6Im1vbm9wb2RpdW0iLCJhdmF0YXIiOiJodHRwczovL2Fzc2V0cy5sZWV0Y29kZS5jb20vdXNlcnMvZGVmYXVsdF9hdmF0YXIuanBnIiwicmVmcmVzaGVkX2F0IjoxNzIwNjI0ODg3LCJpcCI6IjEwMy45NC4xODUuMjQ4IiwiaWRlbnRpdHkiOiJkOTRhMjdhNTZlNmExNDNkNGM5MDBiOTAxNGQ2YmE1ZCIsImRldmljZV93aXRoX2lwIjpbIjk0NjNlYTdjZWZmOTdmZWIxMjBkNjkwMmU4YzdhMzUzIiwiMTAzLjk0LjE4NS4yNDgiXSwic2Vzc2lvbl9pZCI6NjU2Mjc0ODcsIl9zZXNzaW9uX2V4cGlyeSI6MTIwOTYwMH0.T1i6iyrY2C6hKfX3KjV_YCADi88Feu1eiU31oqwC008; 87b5a3c3f1a55520_gr_last_sent_sid_with_cs1=5b3ed5a7-804e-4efe-a81b-de0fe1aede2f; 87b5a3c3f1a55520_gr_last_sent_cs1=monopodium; 87b5a3c3f1a55520_gr_cs1=monopodium; _ga_CDRWKZTDEX=GS1.1.1720624028.1.1.1720624899.15.0.0; _ga=GA1.2.1707193943.1720624026; _dd_s=rum=0&expire=1720625804207' \
  -H 'origin: https://leetcode.com' \
  -H 'referer: https://leetcode.com/contest/biweekly-contest-135/' \
  -H 'sec-ch-ua: "Chromium";v="122", "Not(A:Brand";v="24", "Microsoft Edge";v="122"' \
  -H 'sec-ch-ua-mobile: ?0' \
  -H 'sec-ch-ua-platform: "Windows"' \
  -H 'sec-fetch-dest: empty' \
  -H 'sec-fetch-mode: cors' \
  -H 'sec-fetch-site: same-origin' \
  -H 'user-agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/122.0.0.0 Safari/537.36 Edg/122.0.0.0' \
  -H 'uuuserid: 9463ea7ceff97feb120d6902e8c7a353' \
  -H 'x-csrftoken: NeXKqwOF2hcvZiK0mejasObr62UH5xcX0wPy9Vv9Dq3bwhdHsR52S4PzMYBEhu5M' \
  --data-raw $'{"operationName":"fetchNotifications","variables":{"first":10},"query":"query fetchNotifications($first: Int\u0021, $after: String) {\  notifications(first: $first, after: $after) {\    edges {\      node {\        id\        notificationId\        modifiedDate\        actioned\        notificationData {\          id\          content\          type\          metadata\          __typename\        }\        __typename\      }\      __typename\    }\    pageInfo {\      endCursor\      hasNextPage\      __typename\    }\    __typename\  }\}\"}'