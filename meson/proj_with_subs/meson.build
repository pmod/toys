project(
 'main',
 version : '1.0',
 subproject_dir : 'subs'
)

project_dependencies = [
 dependency('mysub1', fallback : ['mysub1', 'dep']),
 dependency('mysub2', fallback : ['mysub2', 'dep'])
]
	
