# LIBCMT
LIBCMT: With this library, you can use every feature in C language even if it's exist or not in your compiler.

## Contents

LIBCMT
---

+ ![](https://cdn.discordapp.com/attachments/1218916303373336688/1218919967995596810/Attributes.png?ex=66096aae&is=65f6f5ae&hm=6c545481e703eee4982b80f824a2376ad76299778128f6e203784ceb86712d00) **Attributes**
	+ ![](https://cdn.discordapp.com/attachments/1218916303373336688/1218923344246734888/align.png?ex=66096dd3&is=65f6f8d3&hm=2f869c7654e262c417a53a55d44f25d37841540a54b191ab73277237c9965137) **[ALIGN](https://github.com/TeomanDeniz/LIBCMT/blob/main/CMT/ATTRIBUTES/ALIGN.h)** - ???
	+ ![](https://cdn.discordapp.com/attachments/1218916303373336688/1218943086470889503/pack.png?ex=66098036&is=65f70b36&hm=673c47ec7e56a820efd2ac0b77cc1d98c6db1df990f1a50219b67086d61d7275) **[PACK](https://github.com/TeomanDeniz/LIBCMT/blob/main/CMT/ATTRIBUTES/PACK.h)** - Packs and removes the padding bytes from your struct.
	+ ![](https://cdn.discordapp.com/attachments/1218916303373336688/1218945295577255956/regparm.png?ex=66098245&is=65f70d45&hm=33ff0a9bad10d1c74a688d690bfecb9560109ab70a6f1fee90de1ca587fc59bd) **[REGPARM](https://github.com/TeomanDeniz/LIBCMT/blob/main/CMT/ATTRIBUTES/REGPARM.h)** - Pass arguments to a function via using CPU registers.

+ ![](https://cdn.discordapp.com/attachments/1218916303373336688/1218928460198707330/environments.png?ex=66097297&is=65f6fd97&hm=684b973798ae306dca1ea71d5de3e8c545bc562c583bdddb3e9d35a256415c81) **Environments**
	+ ![](https://cdn.discordapp.com/attachments/1218916303373336688/1218953738991960124/cache.gif?ex=66098a22&is=65f71522&hm=39aa0c84bab725a72720024ba8a634f1e23f71f696f673571c6fbbd76d7c0d50) **[CACHE](https://github.com/TeomanDeniz/LIBCMT/blob/main/CMT/ENVIRONMENTS/CACHE.h)** - You can get informatig about CPU architecture.

+ ![](https://cdn.discordapp.com/attachments/1218916303373336688/1218926507997790258/functions.png?ex=660970c6&is=65f6fbc6&hm=5a2870988e40f1f3d9f0e10f9c696509f7e1e4a1bbe558f225f5934b7af838ce) **Functions**
	+ ![](https://cdn.discordapp.com/attachments/1218916303373336688/1218934814326132818/dll.png?ex=66097882&is=65f70382&hm=7b0623fdb10ad1ce4ec0858998d0d96221ac504af701e0489ce56369ab0a1167) **[DLL](https://github.com/TeomanDeniz/LIBCMT/blob/main/CMT/FUNCTIONS/DLL.h)** - Cross platform dynamic link library functions.
	+ ![](https://cdn.discordapp.com/attachments/1218916303373336688/1218936387043332196/prefetch.png?ex=660979f9&is=65f704f9&hm=e5b249ac28fec7a9381dbbca78ba66211f1fe691de8b80693cd21675bd1c3c9b) **[PREFETCH](https://github.com/TeomanDeniz/LIBCMT/blob/main/CMT/FUNCTIONS/PREFETCH.h)** - Reduces the cache-miss latency of memory accesses.
	+ ![](https://cdn.discordapp.com/attachments/1218916303373336688/1218916306691035226/push_pop.png?ex=66096745&is=65f6f245&hm=5102e330c0c350f44b9d6b676b98005c951f7ffd508944c2643930095a1b6f21) **[PUSH & POP](https://github.com/TeomanDeniz/LIBCMT/blob/main/CMT/FUNCTIONS/PUSH_POP.h)** - Add the value to CPU stack (Only for register variables)

+ ![](https://cdn.discordapp.com/attachments/1218916303373336688/1218946997969752145/keywords.png?ex=660983db&is=65f70edb&hm=fdcf537f75cb7b8fdf4c1e9f63981b1f265bea18b4d65cad572191793fdaed69) **Keywords**
	+ ![](https://cdn.discordapp.com/attachments/1218916303373336688/1218949391792996492/inline.png?ex=66098615&is=65f71115&hm=c7590feb2e5c7cb15408a1ab1a90191fc72435bb81e9e1409f784c90e833246f) **[INLINE](https://github.com/TeomanDeniz/LIBCMT/blob/main/CMT/KEYWORDS/INLINE.h)** - Inlines your function on specific compilers.
	+ ![](https://cdn.discordapp.com/attachments/1218916303373336688/1218950372228333689/no_return.png?ex=660986ff&is=65f711ff&hm=6ac35d761581293c736e08c19266f26244e208fba003ae276c29ffde5c39516a) **[NORETURN](https://github.com/TeomanDeniz/LIBCMT/blob/main/CMT/KEYWORDS/NORETURN.h)** - Optimises your function if there is an exit in it.
	+ ![](https://cdn.discordapp.com/attachments/1218916303373336688/1218951382086979688/unused.png?ex=660987f0&is=65f712f0&hm=177e8b965e7c5aa3fe9f550fdcae0389b7e6b2f941e2e9f3fb9c52d4e3eaa6ea) **[UNUSED](https://github.com/TeomanDeniz/LIBCMT/blob/main/CMT/KEYWORDS/UNUSED.h)** - Tag the functions/variables that may not used in the project. (For ignore warnings)

Graphics
---