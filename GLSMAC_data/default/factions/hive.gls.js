return {
	name: 'Hive',
	colors: {
		text: #to_color(0, 97, 255),
		border: #to_color(0, 0, 255),
	},
	bases: {
		render: {
			type: 'sprite_grid',
			file: 'hive.pcx',
			grid_x: 1, grid_y: 1,
			cell_width: 100, cell_height: 75,
			cell_padding: 1,
		},
		names: #game.factions.import_base_names('hive.txt'),
	},
};
