;================================================== ARM ==================================================

		{"tank.vk65" ; Panther tanks
			{clip
				{viewMin		-12}	; camera rotate upward limit (looking down)
				{viewMax		 41}	; camera rotate downward limit (looking up)
				{distanceMin	002}	; camera min distance from object. value / 20 = meters
				{distanceMax	350}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone "fxfire3"}
				{faroffset 0 0 30}
				{nearoffset 5 0 16}
				{camera "zoom1"}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				{linkBone "fxfire3"}
				{offset 55 0 6}
				{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_tzf_5b"}
				{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				{distance 30}
				{distanceSet 0}
				{delta 0}
				{no_rim_light}
				{camera "zoom1.5"}
				{ManualAccuracyZoom}
				{blur_strength 5}
				{disable_fow 0}
				{soundEffect "enclosed_vehicle"}
			}
			{level ;2
				{camera "zoom5"}
			}
		}

		{"artillery_2.common"
			{clip
				{viewMin		-40	}	; camera rotate upward limit (looking down)
				{viewMax		30	}	; camera rotate downward limit (looking up)
				{distanceMin	1	}	; camera min distance from object. value / 20 = meters
				{distanceMax	350	}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone "basis"}
				{faroffset 0 0 85}
				{nearoffset -50 0 30}
				(mod "hardcore"
					{hide_crosshair 1}
					{hide_hitmarker 1}
				)
				{blur_strength 2}
				{disable_fow 0}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				{vignette "/texture/common/environment/lens_effects/zoom_vignette_artillery_01"}
				{blur_mask "/texture/common/environment/lens_effects/zoom_vignette_infantry_01_mask"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_artillery_bp"}
				{distance 50}
				{distanceset 1}
				{delta 0}
				{linkBone "turret"}
				{offset 75 0 300}
				{gunnerviewoff 1}
				{camera "zoom1.5"}
				;{ManualAccuracyZoom}
				{blur_strength 10}
				{disable_fow 0}
				{no_rim_light}
				{soundEffect "opentop_vehicle"}
			}
			{level ;2
				{camera "zoom4"}
				{offset 100 0 500}
			}
			{level ;3
				{camera "zoom4"}
				{offset 200 0 600}
			}
			{level ;4
				{camera "zoom4"}
				{offset 300 0 700}
			}
			{level ;5
				{camera "zoom4"}
				{offset 400 0 800}
			}
			{level ;6
				{camera "zoom4"}
				{offset 500 0 900}
			}
			{level ;7
				{camera "zoom4"}
				{offset 600 0 1000}
			}
		}
		
{"td.t28_85"
	{clip
		{viewMin		-12	}	; camera rotate upward limit (looking down)
		{viewMax		20	}	; camera rotate downward limit (looking up)
		{distanceMin	200	}	; camera min distance from object. value / 20 = meters
		{distanceMax	350	}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 70}
		{nearoffset -45 0 55}
		{camera "zoom1"}
		{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "visor1"}
		{offset 8 -17 3}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_rus_tsh15"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 5}
		{distanceSet 0}
		{delta 0}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 10}
		{disable_fow 0}
		{no_rim_light}
		{soundEffect "enclosed_vehicle"}
	}
	{level ;2
		{camera "zoom4"}
	}
}

		{"tank.light_us37"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{vignette		"/texture/common/environment/lens_effects/vehicle_telescope_us_37"}
				{blur_mask		"/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		70 -5 12	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}

		{"tank.medium_us76"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{vignette		"/texture/common/environment/lens_effects/vehicle_telescope_us_76"}
				{blur_mask		"/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		80 8 12	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}
		
		