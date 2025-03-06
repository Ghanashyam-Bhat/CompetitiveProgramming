

commands = [
   "cd users",
   "cd .",
   "cd admin",
   "cd /",
   "cd volumes",
   "cd checkers",
   "cd ..",
   "cd ..",
   "cd ..",
   # "cd admin",
   # "cd /",
   # "cd volumes",
   # "cd checkers",
]

def solution( commands ):
   root = "/"
   path = root
   for cmd in commands:
      dir = cmd.split("cd ")[ 1 ]
      if dir=="..":
         if path.endswith("/"):
            continue
         else:
            path = path.split("/")
            path.pop()
            if len( path )>1:
               path = "/".join( path )
            else:
               path = root
      elif dir==".":
         continue
      elif dir=="/":
         path = root
      else:
         if path.endswith("/"):
            path += dir
         else:
            path += ("/"+dir)
   return path

ans = solution( commands )
print( ans )