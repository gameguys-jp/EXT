.section .data._22bandwidth_face, "aw"
.balign 4

.global _22bandwidth_face
.type _22bandwidth_face, @object
.size _22bandwidth_face, (_22bandwidth_face_end - _22bandwidth_face)
_22bandwidth_face:
	.incbin "C:/Users/6120n/Downloads/PS1Game-master/PS1Game-master/textures/22bandwidth_face.tim"

.local _22bandwidth_face_end
_22bandwidth_face_end:

.balign 4

.section .data._22bandwidth_face_size, "aw"
.balign 4

.global _22bandwidth_face_size
.type _22bandwidth_face_size, @object
.size _22bandwidth_face_size, 4
_22bandwidth_face_size:
	.int (_22bandwidth_face_end - _22bandwidth_face)
