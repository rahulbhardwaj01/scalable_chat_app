warning: in the working copy of 'client/src/fetch/groupFetch.ts', LF will be replaced by CRLF the next time Git touches it
warning: in the working copy of 'server/src/index.ts', LF will be replaced by CRLF the next time Git touches it
[1mdiff --git a/client/src/fetch/groupFetch.ts b/client/src/fetch/groupFetch.ts[m
[1mindex ee8b8ec..2feaa1b 100644[m
[1m--- a/client/src/fetch/groupFetch.ts[m
[1m+++ b/client/src/fetch/groupFetch.ts[m
[36m@@ -34,7 +34,7 @@[m [mexport async function fetchChatGroups(token: string) {[m
 export async function fetchChatGroup(id: string) {[m
   try {[m
     const res = await fetch(`${CHAT_GROUP_URL}/${id}`, {[m
[31m-      cache: "no-cache",[m
[32m+[m[32m      cache: "no-cache",  //always fetch new details[m
       next: {[m
         revalidate: 60 * 60, // 1 hour[m
         tags: ["dashboard"],[m
[1mdiff --git a/server/src/index.ts b/server/src/index.ts[m
[1mindex 6513e36..1f524a9 100644[m
[1m--- a/server/src/index.ts[m
[1m+++ b/server/src/index.ts[m
[36m@@ -55,7 +55,11 @@[m [msetupSocket(io);[m
 export { io };[m
 [m
 // * Middleware[m
[31m-app.use(cors());[m
[32m+[m[32mapp.use(cors({[m
[32m+[m[32m  origin: [process.env.CLIENT_APP_URL], // make sure this is the same URL used on Vercel[m
[32m+[m[32m  credentials: true,[m
[32m+[m[32m}));[m
[32m+[m
 app.use(express.json());[m
 app.use(express.urlencoded({ extended: false }));[m
 app.use(morgan(morganFormat));[m
